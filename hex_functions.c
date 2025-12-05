#include "main.h"
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int show_hex(UserArgument* usrarg)
{
    size_t n, total_read = 0;
    unsigned char buf[usrarg->row_size];

    if(usrarg->verbose==1){
        printf("Reading file.\n");
    }

    while ((n=fread(&buf, 1, usrarg->row_size, usrarg->fp))>0){

        if (usrarg->length > 0 && total_read + n > usrarg->length) {
            n = usrarg->length - total_read;
        }

        size_t offset = ftell(usrarg->fp) - n;


        if (usrarg->offsetf==1){
            if (usrarg->colour==1)
                printf("\033[36m%08zX\033[0m | ", offset);
            else
                printf("%08zX | ", offset);
        }

        for (size_t i = 0; i < usrarg->row_size; i++) {
            if (i%usrarg->group==0){
                printf(" ");
            }
            if (i < n){
                if (usrarg->colour==1){
                    if (buf[i]==0x00)
                        printf("\033[34m%02X\033[0m", buf[i]);
                    else if (buf[i]==0xFF)
                        printf("\033[31m%02X\033[0m", buf[i]);
                    else
                        printf("\033[37m%02X\033[0m", buf[i]);
                } else {
                    printf("%02X", buf[i]);
                }
            } else {
                printf(" ");
            }
        }

        // Canonical mode
        if(usrarg->canonical==1){
            printf("|");
            for(size_t i=0;i<n;i++){
                if(isprint(buf[i])){
                    if(usrarg->colour==1)
                        printf("\033[33m%c\033[0m",buf[i]);
                    else
                        putchar(buf[i]);
                } else{
                    if(usrarg->colour==1)
                        printf("\033[90m.\033[0m");
                    else
                        printf(".");
                }
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
