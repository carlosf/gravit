/*

Graviton - A gravity simulator
Copyright 2003-2005 Gerald Kaszuba

Graviton is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

Graviton is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Graviton; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/

#include "graviton.h"

int configRead(char *filename) {

	FILE *fp;
	char buffer[1024];

	fp = fopen(filename, "rb");
	if (!fp) {

		conAdd(2, "Could not open script");
		return 0;

	}

	while (fgets(buffer, 1024, fp)) {
	int len = strlen(buffer) - 1;

		while (len >= 0 && (isspace(buffer[len]) || buffer[len] == 13 || buffer[len] == 10)) buffer[len--] = 0;
		if (len <= 0 || buffer[0] == '#') continue;
		cmdExecute(buffer);
	}

	return 1;

}