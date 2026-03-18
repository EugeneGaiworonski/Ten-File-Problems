/*
    Name: FILEARC.C

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
    Date: 18.03.26 13:50
    Description: Copies the contents of the existing file orig.txt 
    to a new file named backup.txt
*/

#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

int main() {
    FILE* srcFile = NULL;
    FILE* arcFile = NULL;
    char ch = 0;
    char pch = 0;
    int cnt = 0;

    // Open source file for reading
    srcFile = fopen("source.txt", "r");
    if (srcFile == NULL) {
        perror("");
        return (errno);
    }

    // Open target file for writing
    arcFile = fopen("source.arc", "w");
    if (arcFile == NULL) {
        perror("");
        fclose(srcFile);
        return (errno);
    }
    
    // File operations
    while (!feof(srcFile)) {
        ch = fgetc(srcFile);
            if (pch == 0) {
                cnt = 1;
                pch = ch;
            } else if (ch == pch) {
                cnt++;
                pch = ch;
            }
            else if (ch != pch) {
                fputc(cnt, arcFile);
                fputc(pch, arcFile);
                cnt = 1;
                pch = ch;
            }
    }
    
    // Close file
    fclose(srcFile);
    fclose(arcFile);
    return 0;
}

