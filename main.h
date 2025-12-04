#pragma once
#include <stdio.h>

#define PROGRAMNAME "shex"
#define PROGRAMVERSION "1.0.0"

typedef struct {
    int row_size;
    FILE* fp;
    int canonical;
    int colour;
} UserArgument;

int show_hex(UserArgument* usrarg);
void help();