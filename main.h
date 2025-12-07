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