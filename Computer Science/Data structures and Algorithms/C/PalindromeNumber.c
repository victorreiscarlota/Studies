/**
 * Given an integer x, return true if x is a palindrome, and false otherwise.
 */

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    // exceptions - non zero numbers ending in zero and negative numbers are not palindromes -
    if (x<0 || (x!=0 && x%10) ==0) {
        return false;
    }

    int original = x;
    int reversed = 0;

    // invert the number
    while (x > 0) {
        int digit = x % 10;
        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return original == reversed;
}

int main() {
    int x;

    do {
        printf("Type an integer number (Type 34 for the code to end): ");
    scanf("%d", &x);

    if(x!=34) {
        printf("Result: %s\n", isPalindrome(x) ? "true" : "false");
    }
    
    }
    while (x != 34);

    return 0;
}
