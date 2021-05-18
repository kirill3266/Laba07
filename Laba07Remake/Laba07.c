#define _CRT_SECURE_NO_WARNINGS
#include "Laba07.h"
#include <stdio.h>

/* calculates string length */
int strlength(char* str) {
	int i = 0;
	for (i = 0; str[i] != 0 && str[i] != '\n'; i++);
	return i;
}

/*converts input string to long integer */
void convert(char* str, int boo) {
	int end = -1;
	if (boo >= 1) end = 0;
	long int out = 0;
	long j = 1;
	int length = strlength(str);
	for (int i = length - 1; i != end; i--) {
		out += (str[i] - 48) * j;
		j *= 10;
	}
	if (end == 0) out *= -1;
	itoah(out, str);
}

/* itoa:  convert n to symbols in s */
void itoah(long int n, char* s)
{
	printf("Vxod!!");
	int i, sign;
	char* Ci = "0123456789ABCDEF";
	unsigned long new = (unsigned)n;
	i = 0;
	do {
		s[i++] = Ci[new % 16];
	} while ((new /= 16) > 0);
	s[i] = '\0';
	reverse(s);
	printf("End: %s\n", s);
}

/* reverses string s */
void reverse(char* s)
{
	int i, j;
	char c;

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
