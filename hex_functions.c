/*
 * Copyright (C) 2025 Selim Öztürk
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int show_hex(UserArgument* usrarg)
{
    size_t n, total_read = 0;
    unsigned char buf[usrarg->row_size];

    if (usrarg->verbose == 1) {
        printf("Reading file.\n");
    }

    while (1) {

        long start_offset = ftell(usrarg->fp);   
        n = fread(buf, 1, usrarg->row_size, usrarg->fp);
        if (n == 0) break;

        // Length limit
        if (usrarg->length > 0 && total_read + n > usrarg->length) {
            n = usrarg->length - total_read;
        }

        size_t offset = (size_t)start_offset;

        // Offset print
        if (usrarg->offsetf == 1) {
            if (usrarg->colour)
                printf("\033[36m%08zX\033[0m | ", offset);
            else
                printf("%08zX | ", offset);
        }

        // HEX DUMP
        for (size_t i = 0; i < usrarg->row_size; i++) {

            if (i % usrarg->group == 0)
                printf(" ");

            if (i < n) {
                if (usrarg->colour) {
                    if (buf[i] == 0x00)
                        printf("\033[34m%02X\033[0m", buf[i]);
                    else if (buf[i] == 0xFF)
                        printf("\033[31m%02X\033[0m", buf[i]);
                    else if (buf[i] >= 0x20 && buf[i] <= 0xfe)
                        printf("\033[93m%02X\033[0m", buf[i]);
                    else
                        printf("\033[37m%02X\033[0m", buf[i]);
                } else {
                    printf("%02X", buf[i]);
                }
            } else {
                printf("  "); 
            }
        }

        
        if (usrarg->canonical == 1) {
            printf(" |");

            for (size_t i = 0; i < n; i++) {
                if (isprint(buf[i])) {
                    if (usrarg->colour)
                        printf("\033[33m%c\033[0m", buf[i]);
                    else
                        putchar(buf[i]);
                } else {
                    if (usrarg->colour)
                        printf("\033[90m.\033[0m");
                    else
                        printf(".");
                }
            }

            
            for (size_t i = n; i < usrarg->row_size; i++) {
                printf(" ");
            }

            printf("|\n");

        } else {
            printf("\n");
        }

        total_read += n;
        if (usrarg->length > 0 && total_read >= usrarg->length)
            break;
    }

    return 0;
}


int write_to_file(UserArgument* usrarg)
{
    size_t n, total_read = 0;
    unsigned char buf[usrarg->row_size];

    if(usrarg->verbose==1){
        printf("Reading and writing file.\n");
    }

    while ((n=fread(&buf, 1, usrarg->row_size, usrarg->fp))>0){

        if (usrarg->length > 0 && total_read + n > usrarg->length) {
            n = usrarg->length - total_read;
        }

        size_t offset = ftell(usrarg->fp) - n;

        for (size_t i = 0; i < usrarg->row_size; i++) {
            if (i > 0 && i % usrarg->group == 0)
                fprintf(usrarg->ofp, " "); 
            if (i < n)
                fprintf(usrarg->ofp, "%02X", buf[i]);
            else
                fprintf(usrarg->ofp, "  "); 
        }
        fprintf(usrarg->ofp, "\n"); 

        total_read += n;
        if (usrarg->length > 0 && total_read >= usrarg->length)
            break;
    }

    return 0;
}
