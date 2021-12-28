/**
 * Copyright (C) 2021 Keyboard Slayer
 * 
 * This file is part of my-mips.
 * 
 * my-mips is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * my-mips is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with my-mips.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "debug.h"

#include <stdio.h>
#include <stdarg.h>

void debug_log(enum LOGLEVEL level, char const *format, ...)
{
    va_list ap;
    va_start(ap, format);

    switch(level)
    {
        case LOG_OK:
        {
            printf("\033[32m[+] ");
            break;
        }

        case LOG_ERROR:
        {
            printf("\033[31m[!] ");
            break;
        }

        case LOG_INFO: 
        {
            printf("\033[33m[?] ");
        }
    }

    printf("\033[0m");
    vprintf(format, ap);
    printf("\n");

    return;
}

