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