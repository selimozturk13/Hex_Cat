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
        {"version",no_argument,0,'V'},
        {"dis-canonical",no_argument,0,'C'},
        {"dis-colourful",no_argument,0,'c'},
        {"skip",required_argument,0,'s'},
        {"verbose", no_argument,0,'v'},
        {"length",required_argument,0,'l'},
        {"only-hex",no_argument,0,1000},
        {"group",required_argument,0,'g'},
        {"output",required_argument,0,'o'},
        {0, 0, 0, 0}
    };
    option_index=0;
    FILE *fp,*ofp;
    UserArgument usrarg={16,NULL,1,1,0,0,0,1,2,NULL};

    while((opt=getopt_long(argc, argv,"hVr:Ccs:vl:g:o:",long_options,&option_index))!=-1){
        switch (opt) {
            case 'h':
                help();
                goto exit;
            case 'r':
                usrarg.row_size=atoi(optarg);
                break;
            case 'V':
                printf("%s\n%s",PROGRAMNAME,PROGRAMVERSION);
                goto exit;
            case 'C':
                usrarg.canonical=0;
                break;
            case 'c':
                usrarg.colour=0;
                break;
            case 's':
                usrarg.skip=atoi(optarg);
                break;
            case 'v':
                usrarg.verbose=1;
                printf("Verbose mode enabled.\n");
                break;
            case 'l':
                usrarg.length=atoi(optarg);
                break;
            case 1000:
                usrarg.canonical=0;
                usrarg.offsetf=0;
                break;
            case 'g':
                usrarg.group=atoi(optarg);
                break;
            case 'o':
                ofp = fopen(optarg, "w");
                if (!ofp){
                    perror("Can not open file");
                    goto error;
                }
                usrarg.ofp=ofp;
                break;
            default:
                printf("\033[31mError:\033[0m Unknown argument.\n");
                help();
                goto error;
        }
    }

    //open the file
    for (int i=optind;i<argc;i++)
    {
        if(usrarg.verbose==1){
            printf("Opening file in binary reading option.\n");
        }
        fp=fopen(argv[i],"rb");
        usrarg.fp=fp;
    }

    if (usrarg.fp==NULL){
        printf("\033[31mError:\033[0m Input file is not spesified.\n");
        help();
        exit(1);
    }


    //skip the bytes
    if (usrarg.skip!=0)
    {
        if(usrarg.verbose==1){
            printf("Skipping bytes.\n");
        }
        fseek(usrarg.fp, usrarg.skip, SEEK_SET);
        if(usrarg.verbose==1){
            printf("Skiped bytes: %ld\n",ftell(usrarg.fp));
        }
    }
    show_hex(&usrarg);
    if (usrarg.ofp!=NULL) {
        fseek(usrarg.fp, usrarg.skip, SEEK_SET);
        if (usrarg.verbose==1){
            printf("Writing to the file\n");
        }
        write_to_file(&usrarg);
    }
    exit:
        if (fp) fclose(fp);
        if (usrarg.fp) fclose(usrarg.fp);
        if (usrarg.ofp) fclose(usrarg.ofp);
        return 0;
    error:
        if (fp) fclose(fp);
        if (usrarg.fp) fclose(usrarg.fp);
        if (usrarg.ofp) fclose(usrarg.ofp);
        return 1;
}