#include <stdio.h>
#include "main.h"


void help() {
    printf("%s\n", PROGRAMNAME);
    printf("Usage: hc [options] <file>\n\n");
    printf("Options:\n");
    printf("  -h, --help             Show this help message and exit\n");
    printf("  -V, --version          Show version information\n");
    printf("  -v, --verbose          Enable verbose mode\n");
    printf("  -r, --row-size <num>   Number of bytes per row (default: 16)\n");
    printf("  -C, --dis-canonical    Disable canonical mode\n");
    printf("  -c, --dis-colourful    Disable coloring\n");
    printf("  -s, --skip <num>       Skip bytes from start of file\n");
    printf("  -l, --length <num>     Limit display to specified number of bytes\n");
    printf("      --only-hex         Display only hex, no ASCII column\n");
    printf("  -g, --group <num>      Group bytes\n");
    printf("  -o, --output <file>    Write hex dump to a file\n");
    printf("\n");
}