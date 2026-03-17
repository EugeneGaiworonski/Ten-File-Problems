/*
	Name: FILECREAT.C
	
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
	Description: The program prompts the user for a text phrase 
	and writes it to the "output.txt" file
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 256

int main() {
    char phrase[MAX_LENGTH];
    FILE *file;

    // Prompt the user for a text phrase
    printf("Enter a text phrase: ");
    
    // Read the string including spaces
    if (fgets(phrase, sizeof(phrase), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Open file for writing
    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Write the phrase to the file
    if (fputs(phrase, file) == EOF) {
        printf("Error writing to file.\n");
        fclose(file);
        return 1;
    }

    // Close the file
    fclose(file);
    
    printf("Phrase successfully written to file output.txt\n");
    
    return 0;
}
