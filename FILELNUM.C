/*
    Name: FILELNUM.C

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
    Date: 16.03.26 11:03
    Description: Сounting the number of lines in a text file
*/

#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 14

int main() {
    char sFileName[MAX_LENGTH] = {"lines.txt"};
    FILE* sFile;
    int lineNumber = 0;

    char buf[80] = { '\0' };
    
    // Open source file for reading
    sFile = fopen(sFileName, "r");
    if (sFile == NULL) {
        perror("");
        return (errno);
    }

    // Line by line reading
    while (fgets(buf, sizeof(buf), sFile)) lineNumber++;

    // Close file
    fclose(sFile);
    printf("File %s contains %d lines\n", sFileName, lineNumber);

    return 0;
}

