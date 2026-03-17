/*
	Name: FILECOPY.C
	
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
	Date: 11.03.26 16:13
	Description: Copies a file from a user-specified source to a target file 
	named "copy.txt". This program will work with any type of file (text, binary, 
	images, etc.) due to the binary mode operations
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 14

int main() {
    char sFileName[MAX_LENGTH] = {0};
    char buf = 0;
	FILE *sFile;
    FILE *tFile;

    // Prompt the user for a source file name
    printf("Enter file name to copy: ");
    
    // Read the string including spaces
    if (scanf("%13s", sFileName) == NULL) {
        printf("Error reading file name.\n");
        return 1;
    }

    // Open source file for reading
    sFile = fopen(sFileName, "rb");
    if (sFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    // Open target file for writing
    tFile = fopen("copy.txt", "wb");
    if (tFile == NULL) {
        printf("Error opening file.\n");
        flose(sFile); // Cleanup the opened source file
		return 1;
    }
		
	// Read/write operations
	while (fread(&buf,1,1,sFile) == 1) fwrite(&buf,1,1,tFile);
    
    // Close the file
    fclose(sFile);
	fclose(tFile);    
    printf("File successfully copied to file copy.txt\n");
    
    return 0;
}
