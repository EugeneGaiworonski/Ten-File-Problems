/*
    Name: FILESTAT.C

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
    Date: 17.03.26 10:36
    Description: Reads the text.txt file and counts the frequency 
    of each Latin letter (including both uppercase and lowercase forms). 
    The results are saved to the stats.txt file.
*/

#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_LENGTH 14
#define ASCIISIZE (0xFF + 1)

int main() {
    char ch = 0;
    int stat[ASCIISIZE] ;
    FILE* file;
    
    for (int i = 0; i < ASCIISIZE; i++) stat[i] = 0;
    
    
    // Open source file for reading
    file = fopen("text.txt", "r");
    if (file == NULL) {
        perror("");
        return (errno);
    }

    // Char by char file reading and counting
    do {
        ch = fgetc(file);
        stat[ch]++;
    } while (ch != EOF);

    // Close file
    fclose(file);
    
    // Open stats.txt for writing
    file = fopen("stats.txt", "w");
    if (file == NULL) {
        perror("");
        return (errno);
    }

    // Write uppercase
    for (int i = 'A'; i <= 'Z'; i++) {
        fprintf(file, "\'%c\': %i\n", i, stat[i]);
    }

    // Write lowercase
    for (int i = 'a'; i <= 'z'; i++) {
        fprintf(file, "\'%c\': %i\n", i, stat[i]);
    }

    fclose(file);

    //printf("File %s created\n", tFileName);

    return 0;
}

