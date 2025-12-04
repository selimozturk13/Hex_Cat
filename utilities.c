#include <stdio.h>
#include "main.h"


void help() {
    printf("Usage: %s [options] <file>\n", PROGRAMNAME);
    printf("\nOptions:\n");
    printf("  -h, --help                Show this help message and exit\n");
    printf("  -V, --version             shows version\n");
    printf("  -i, --input-file <file>   Specify input file\n");
    printf("  -r, --row-size <number>   Number of lines/bytes per row (default: 16)\n");
    printf("\n");
}