// Maurizio Brancato

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myFlush();

int main() {

	int nOfLines, count = 0;
	char words[10 + 1][100 + 1];// words created
	char alphabet[] = { "abcdefghijklmnopqrstuvwxyz" };// letters to compare



	do {
		scanf("%i", &nOfLines);
		if (nOfLines > 10) {
			printf("ERROR: number has to be less than 10, try again.\n ");
			
		}// end if
	} while (nOfLines > 10);

	

	for (int i = 0; i < nOfLines; i++) {
		scanf("%s", words[i]);
		
	}

	for (int i = 0; i < nOfLines; i++) {
		for (int j = 0; j < strlen(words[i]) ; j++) {
			for (int g = 0; g < strlen(alphabet); g++) {
				if (words[i][j] == alphabet[g]) {
					
					if (count == 1) {
						if (g >= 14) {
							printf("%c", alphabet[(g + 14) - 26]);
							count = 0;
						}
						else {
							printf("%c", alphabet[g + 14]);
							count = 0;
						}
					}m,
					else {
						if (g >= 13) {
							printf("%c", alphabet[(g + 13) - 26]);
						}else  printf("%c", alphabet[g + 13]);
						if (words[i][j] == 'a' || words[i][j] == 'e' || words[i][j] == 'i' || words[i][j] == 'o' || words[i][j] == 'u') {
							count++;
						}
					}				
				}
			}
		}
		printf("\n");
		count = 0;
	}



	

	
	
	return 0;
}//end of main

 ////////////////////////////////////////////////////////



