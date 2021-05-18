#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "Laba07.h"

int main() {
	char ch = 0;
	int v = 0, N = 11;
	int boo = 0;
	char* str = (char*)malloc(N * sizeof(char));;
	printf("Vvedite chislo:\n");
	do {
		scanf("%c", &ch);
		if ((ch < 49 || ch>57) && ch != '\n' && ch != ' ' && ch != '\t')boo++;
		str[v] = ch;
		v++;
		if (v >= N - 1) {
			N *= 2;
			str = (char*)realloc(str, N * sizeof(char));
			printf("New N is: %d\n", N);
			if (!str) {
				printf("Allocation error!\n");
				return 1;
			}
		}
	} while (ch != '\n' && ch != ' ' && ch != '\t' && ch >= 49 && ch <= 57 || ((boo == 1) && (ch == '-')));
	if (!(ch >= 49 && ch <= 57) && ch != '\n') {
		str[v - 1] = 0;
	}
	else {
		str[v] = 0;
	}
	if (*str == '\n' || *str == 0 || boo >= 2) {
		printf("Input error!\n");
		return 1;
	}
	printf("Vxod");
	convert(str, boo);
	free(str);
	return 0;
}