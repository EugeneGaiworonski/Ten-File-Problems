/*
    Name: FILETRIM.C

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

int main() {
    FILE* file;
    FILE* tmpFile;
    char buffer[255];

    // Open source file for reading
    file = fopen("data.txt", "r");
    if (file == NULL) {
        perror("");
        return (errno);
    }

    // Open temporary file    
    tmpFile = tmpfile();
    if (tmpFile == NULL) {
        perror("");
        return (errno);
    }
    
    // File operations
    while (fgets(buffer, 255, file) != NULL)
      if (buffer[0] != '\n') fprintf(tmpFile, buffer, "%s");
    rewind(tmpFile);
    //close(file);
    file = freopen("data.txt", "w", file);
    if (file == NULL) {
        perror("");
        return (errno);
    }
    while (fgets(buffer, 255, tmpFile) != NULL) fprintf(file, buffer, "%s");
    
    // Close file
    fclose(tmpFile);
    fclose(file);
    return 0;
}

