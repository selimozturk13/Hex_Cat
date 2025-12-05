#pragma once
#include <stdio.h>

#define PROGRAMNAME "Hex Cat"
#define PROGRAMVERSION "1.0.0"

typedef struct {
    int row_size;
    FILE* fp;
    int canonical;
    int colour;
    int skip;
    int verbose;
    int length;
    int offsetf;
    int group;
    FILE* ofp;
} UserArgument;

int show_hex(UserArgument* usrarg);
int write_to_file(UserArgument* usrarg);
void help();