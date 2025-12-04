#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char *argv[])
{
    int opt,option_index;
    static struct option long_options[]={
        {"help",no_argument,0,'h'},
        {"row-size",required_argument,0,'r'},
        {"input-file",required_argument,0,'i'},
        {"version",no_argument,0,'V'},
        {"canonical",no_argument,0,'C'},
        {"colourful",no_argument,0,'c'},
        {0, 0, 0, 0}
    };
    option_index=0;
    FILE* fp;
    UserArgument usrarg={16,NULL,0,0};

    while((opt=getopt_long(argc, argv,"hVr:i:Cc",long_options,&option_index))!=-1){
        switch (opt) {
            case 'h':
                help();
                exit(0);
            case 'i':
                fp=fopen(optarg,"rb");
                usrarg.fp=fp;
                break;
            case 'r':
                usrarg.row_size=atoi(optarg);
                break;
            case 'V':
                printf("%s\n%s",PROGRAMNAME,PROGRAMVERSION);
                exit(0);
            case 'C':
                usrarg.canonical=1;
                break;
            case 'c':
                usrarg.colour=1;
                break;
            default:
                printf("\033[31mError:\033[0m Unknown argument.\n");
                help();
                exit(1);
        }
    }
    if (usrarg.fp==NULL){
        printf("Error: Input file is not spesified.");
        help();
        exit(1);
    }
    show_hex(&usrarg);
    fclose(fp);
    return 0;
}