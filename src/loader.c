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

#include "debug.h"
#include "loader.h"

#include <assert.h>
#include <elf.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <byteswap.h>

void elf_load(MAYBE_UNUSED mips_t *mips, char const *filename)
{
    long size;
    uint32_t i;
    Elf32_Ehdr header = {0};
    MAYBE_UNUSED Elf32_Phdr prog = {0};
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        perror("");
        return;
    }

    assert(fseek(fp, 0, SEEK_END) == 0);
    size = ftell(fp);
    assert(fseek(fp, 0, SEEK_SET) == 0);

    if (size == 0)
    {
        debug_log(LOG_ERROR, "Can't load empty binaries");
        fclose(fp);
        exit(1);
    }

    fread(&header, 1, sizeof(Elf32_Ehdr), fp);

    if (memcmp(header.e_ident, ELFMAG, 4) > 0)
    {
        debug_log(LOG_ERROR, "Invalid ELF file (Magic: %x%x%x%x)", header.e_ident[0],
            header.e_ident[1], header.e_ident[2], header.e_ident[3]);

        exit(1);
    }

    if (size * 2 > MEMORY_65K)
    {
        debug_log(LOG_OK, "Allocating 65K of RAM");
        mips->memory = malloc(MEMORY_65K + 1);
        assert(mips->memory != NULL);
    }

    else if (size * 2 > MEMORY_16M)
    {
        debug_log(LOG_OK, "Allocating 16M of RAM");
        mips->memory = malloc(MEMORY_16M + 1);
    }

    else if (size * 2 > MEMORY_4G)
    {
        debug_log(LOG_OK, "Allocating 4G of RAM");
        mips->memory = malloc(MEMORY_4G + 1);
    }

    else 
    {
        debug_log(LOG_ERROR, "Your binary is too big !");
        fclose(fp);
        exit(1);
    }

    for (i = 0; i < __bswap_16(header.e_phnum); i++)
    {
    }
}
