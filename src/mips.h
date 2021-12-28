/*
 * Copyright (C) 2021  Keyboard Slayer
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MYMIPS_MIPS_H
#define _MYMIPS_MIPS_H

#define MEMORY_65K 0x0000ffff
#define MEMORY_16M 0x00ffffff
#define MEMORY_4G  0xffffffff

#include <stdint.h>
#include "macro.h"

typedef struct MIPS
{
    uint32_t registers[32];
    uint32_t hi;
    uint32_t lo;
    uint32_t pc;
    uint8_t *memory;
    uint8_t nline;
} mips_t;

#endif /* !_MYMIPS_MIPS_H */
