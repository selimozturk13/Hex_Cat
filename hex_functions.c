#include "main.h"
#include <stdio.h>
#include <ctype.h>

int show_hex(UserArgument* usrarg)
{
    size_t n,offset=0;
    unsigned char buf[usrarg->row_size];
    while ((n=fread(&buf, 1, usrarg->row_size, usrarg->fp))>0){
        printf("Offset: %07zu | ",offset);
        for (size_t i = 0; i < usrarg->row_size; i++) {
            
            if (i < n)
                printf(" %02X ", buf[i]);
            else
                printf("  ");                  
        }
        //Canonical Mode
        if(usrarg->canonical==1){
            printf("|");
            for(size_t i=0;i<n;i++)
            {
                if(isprint(buf[i])){
                    putchar(buf[i]);
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