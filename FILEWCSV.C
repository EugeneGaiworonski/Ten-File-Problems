/*
    Name: FILEWCSV.C

    Copyright: (C) 2026 E. Gaiworonski
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published
    by the Free Software Foundation, either version 3 of the License,
    or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty
    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.

    Author: E. Gaiworonski
    Date: 17.03.26 14:48
    Description: Reads a simple CSV file data.csv and displays its contents on the screen
*/

#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define ASCIISIZE (0xFF + 1)

int main() {
    char ch = 0;
    FILE* file;
    
    for (int i = 0; i < ASCIISIZE; i++);
    
    
    // Open source file for reading
    file = fopen("data.csv", "r");
    if (file == NULL) {
        perror("");
        return (errno);
    }

    // Char by char file reading and printing
    do {
        ch = fgetc(file);
        switch (ch) {
            case 0x1A: break;
            case 0x1D: {printf("\n"); break;};
            case ',': {printf("\t"); break; };
            default: printf("%c", ch);
        }
    } while (ch != EOF);

    // Close file
    fclose(file);
    return 0;
}

