/*
    Name: FILEBСKP.C

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
    Date: 18.03.26 9:45
    Description: Copies the contents of the existing file orig.txt 
    to a new file named backup.txt
*/

#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

int main() {
    FILE* file;
    FILE* bkpFile;
    char buffer[255];

    // Open source file for reading
    file = fopen("orig.txt", "r");
    if (file == NULL) {
        perror("");
        return (errno);
    }

    // Open target file for writing
    bkpFile = fopen("backup.txt", "w");
    if (file == NULL) {
        perror("");
        fclose(file);
        return (errno);
    }
    
    // File operations
    while (fgets(buffer, 255, file) != NULL) fprintf(bkpFile, buffer, "%s");
    
    // Close file
    fclose(bkpFile);
    fclose(file);
    return 0;
}

