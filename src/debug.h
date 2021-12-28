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

#ifndef _MYMIPS_DEBUG_H
#define _MYMIPS_DEBUG_H

enum LOGLEVEL 
{
    LOG_OK,
    LOG_ERROR,
    LOG_INFO
};

void debug_log(enum LOGLEVEL level, char const *format, ...);

#endif /* !_MYMIPS_DEBUG_H */
