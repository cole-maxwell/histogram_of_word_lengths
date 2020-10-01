#include <stdio.h>
#include <stdlib.h>

#define OUT 0
#define IN  1
#define MAX 28
#define BLOCK 4000

int alphanumeric(char c) {

	return ('a' <= c && c <= 'z') ||
		   ('A' <= c && c <= 'Z') ||
		   ('0' <= c && c <= '9');
}

int main(int argc, char *argv[]) {
	int c, state = OUT, length = 0, i, j, count[MAX];
	char word[30];

	for (i = 0; i < MAX; i++) count[i] = 0;

	while ((c = getchar()) != EOF) {
		if (alphanumeric(c)) {
		  	word[length++] = c;
		  	state = IN;
		}else {
	  		if (state == IN) {
			
				count[length]++;				
				if (length == 27){
		  			word[length] = '\0';
		  			printf("%s\n\n", word);
				}
				length = 0;		
		  	}
		  	state = OUT;
		}
	}


	for (i = 1; i < MAX; i++) {
		printf("%2d %6d ", i, count[i]);
		for (j = 0; j < (count[i] + BLOCK - 1) / BLOCK; j++)
	  		printf("*");
		printf("\n");
	}

	return 0;
}
