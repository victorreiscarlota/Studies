/**
 * Exercise: Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.
*/

#include <stdio.h>
#include <ctype.h>

int romanToInt(char *s) {
    int result = 0;

    while (*s) {
        switch (toupper(*s)) {
            case 'I':
                if (*(s + 1) == 'V' || *(s + 1) == 'X') {
                    result -= 1;
                } else {
                    result += 1;
                }
                break;

            case 'X':
                if (*(s + 1) == 'L' || *(s + 1) == 'C') {
                    result -= 10;
                } else {
                    result += 10;
                }
                break;

            case 'C':
                if (*(s + 1) == 'D' || *(s + 1) == 'M') {
                    result -= 100;
                } else {
                    result += 100;
                }
                break;

            case 'V':
                result += 5;
                break;

            case 'L':
                result += 50;
                break;

            case 'D':
                result += 500;
                break;

            case 'M':
                result += 1000;
                break;

            default:
                return -1;
        }

        s++;
    }

    return result;
}

int isValidRoman(char *s) {
    while (*s) {
        if (toupper(*s) != 'I' && toupper(*s) != 'V' && toupper(*s) != 'X' && toupper(*s) != 'L' &&
            toupper(*s) != 'C' && toupper(*s) != 'D' && toupper(*s) != 'M') {
            return 0;
        }
        s++;
    }

    return 1;
}

int main() {
    char romanNumeral[16];

    while (1) {
        printf("Enter a Roman numeral (type '8' to end the code): ");
        if (scanf("%s", romanNumeral) != 1) {
            printf("Invalid input. Please enter a valid Roman numeral.\n");
            while (getchar() != '\n');
        } else if (romanNumeral[0] == '8' && romanNumeral[1] == '\0') {
            printf("Ending the code.\n");
            break;
        } else if (!isValidRoman(romanNumeral)) {
            printf("Invalid Roman numeral. Please enter a valid Roman numeral (e.g., 'III').\n");
        } else {
            printf("Roman numeral entered: %s\n", romanNumeral);
            printf("Equivalent integer: %d\n", romanToInt(romanNumeral));
        }
    }

    return 0;
}
