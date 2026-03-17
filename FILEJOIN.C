/*
    Name: FILEJOIN.C

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
    Date: 13.03.26 14:13
    Description: Process two text files file1.txt and file2.txt, 
    merging their contents into one file result.txt.
*/

#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 14

int main() {
    char s1FileName[MAX_LENGTH] = {"file1.txt"};
    char s2FileName[MAX_LENGTH] = {"file2.txt"};
    char tFileName[MAX_LENGTH] = {"result.txt"};

    FILE* s1File;
    FILE* s2File;
    FILE* tFile;

    char buf = 0;
    
    // Open first source file for reading
    s1File = fopen(s1FileName, "rb");
    if (s1File == NULL) {
        perror("");
        return (errno);
    }

    // Open second source file for reading
    s2File = fopen(s2FileName, "rb");
    if (s2File == NULL) {
        perror("");
        return (errno);
    }

    // Open target file for writing
    tFile = fopen(tFileName, "wb");
    if (tFile == NULL) {
        perror("");
        fclose(s1File); // Cleanup the opened source files
        fclose(s2File); 
        return (errno);
    }

    // Read/write operations
    while (fread(&buf, 1, 1, s1File) == 1) fwrite(&buf, 1, 1, tFile);
    buf = 0x0D; fwrite(&buf, 1, 1, tFile);
    buf = 0x0A; fwrite(&buf, 1, 1, tFile);
    while (fread(&buf, 1, 1, s2File) == 1) fwrite(&buf, 1, 1, tFile);

    // Close the files
    fclose(s1File);
    fclose(s2File);
    fclose(tFile);
    
    printf("Files %s and %s successfully merged to file %s\n", s1FileName, s2FileName, tFileName);

    return 0;
}

