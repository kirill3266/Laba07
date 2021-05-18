#include "dop.h"


int main() {
	char ch = 0;
	int v = 0, N = 11;
	int minboo = 0;
	int dotboo = 0;
	char* str = (char*)malloc(N * sizeof(char));
	char* ptrEnd= 0;
	int isdiff = 1;
	printf("Vvedite chislo:\n");
	do {
		scanf("%c",&ch);
		if (ch == ' ' || ch == '\t') {
			ch = '0';
			continue;
		}
		if (ch == '-') minboo++;

		else if (ch == '.') dotboo++;

		if (((str[v - 1] == '-' || v == 0) && (ch == 'I' || ch == 'i' || ch == 'n' || ch == 'N')) || ch == 'e') {
			printf("is diff is 0\n");
			isdiff = 0;
		}
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
	} while ((ch >= 48 && ch <= 57 || ch == '-' || ch == '.') && isdiff == 1);

	if (isdiff == 0) {
		do
		{
			printf("Vxod!\n");
			scanf("%c",&ch);
			if (ch == ' ' || ch == '\t') {
				ch = 'n';
				continue;
			}
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
		} while (isalnum(ch)||ch=='-');
	}
	str[v - 1] = 0;

	if (minboo >= 2 || dotboo >= 2) {
		printf("Input error!\n");
		return 1;
	}

	printf("Out is: %lf", strtod1(str, ptrEnd));
	return 0;
}