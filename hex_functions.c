#include "main.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int show_hex(UserArgument* usrarg)
{
    size_t n,offset=0;
    unsigned char buf[usrarg->row_size];
    while ((n=fread(&buf, 1, usrarg->row_size, usrarg->fp))>0){
        printf("Offset: %07zu | ",offset);
        for (size_t i = 0; i < usrarg->row_size; i++) {
            
            if (i < n){
                if (usrarg->colour==1){
                    char hex[20];
                    sprintf(hex, "%02X", buf[i]);
                    if (strcmp(hex, "00") == 0){
                        printf("\033[34m %02X \033[0m",buf[i]);
                    }
                    else if (strcmp(hex, "FF") == 0){
                        printf("\033[31m %02X \033[0m",buf[i]);
                    }
                    else{
                        printf(" %02X ", buf[i]);
                    }
                }
                else{
                    printf(" %02X ", buf[i]);
                }
                
            }
            else{
                printf("  ");      
            }            
        }
        //Canonical Mode
        if(usrarg->canonical==1){
            printf("|");
            for(size_t i=0;i<n;i++)
            {
                if(isprint(buf[i])){
                    if (usrarg->colour==1){
                        printf("\033[32m%c\033[0m",buf[i]);
                    }
                    else {
                        putchar(buf[i]);
                    }
                    
                } else{
                    putchar('.');
                }
            }
            printf("|\n");
        }
        else {
            printf("\n");
        }
        offset+=n;
    }
    return 0;
}