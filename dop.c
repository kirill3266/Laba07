#include "dop.h"

int strcmp(char* s1, char* s2) {
    while ((*s1 != 0) && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

double strtod1( char* str, char** endptr) {
    double result = 0.0;
    char signedResult = '\0';
    char signedExponent = '\0';
    int decimals = 0;
    int isExponent = 0;
    int hasExponent = 0;
    int hasResult = 0;
    // exponent is logically int but is coded as double so that its eventual
    // overflow detection can be the same as for double result
    double exponent = 0.0;
    char c;

    if (strcmp(str,(char*) "inf") == 0) {
        result = INFINITY;
        return result;
    }
    else if (strcmp(str,(char*) "-inf") == 0) {
        result = -INFINITY;
        return result;
    }
    else if (strcmp(str,(char*) "nan") == 0) {
        result = -NAN;
        return result;
    }
    else if (strcmp(str,(char*) "-nan") == 0) {
        result = NAN;
            return result;
    }

    for (; '\0' != (c = *str); ++str) {
        if ((c >= '0') && (c <= '9')) {
            int digit = c - '0';
            if (isExponent) {
                exponent = (10 * exponent) + digit;
                hasExponent = 1;
            }
            else if (decimals == 0) {
                result = (10 * result) + digit;
                hasResult = 1;
            }
            else {
                result += (double)digit / decimals;
                decimals *= 10;
            }
            continue;
        }

        if (c == '.') {
            if (!hasResult) break; // don't allow leading '.'
            if (isExponent) break; // don't allow decimal places in exponent
            if (decimals != 0) break; // this is the 2nd time we've found a '.'

            decimals = 10;
            continue;
        }

        if ((c == '-') || (c == '+')) {
            if (isExponent) {
                if (signedExponent || (exponent != 0)) break;
                else signedExponent = c;
            }
            else {
                if (signedResult || (result != 0)) break;
                else signedResult = c;
            }
            continue;
        }

        if (c == 'e') {
            if (!hasResult) break; // don't allow leading 'E'
            if (isExponent) break;
            else isExponent = 1;
            continue;
        }

        break; // unexpected character
    }

    if (isExponent && !hasExponent) {
        while (*str != 'E')
            --str;
    }

    if (!hasResult && signedResult) --str;

    if (endptr) *endptr = str;
    for (; exponent != 0; --exponent) {
        if (signedExponent == '-') result /= 10;
        else result *= 10;
    }
    if (signedResult == '-' && result != 0) result = -result;

    return result;
}