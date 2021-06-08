#include <stdio.h>
#include <stdint.h>

/*
1011 0101: num

010 110 101


num >> 6
0000 0010: 2
2 & 1

0000 0010: 2 &
0000 0111: 7
----------
0000 0000: 0

1 7 7

*/

int main(void) {
    uint8_t num;
    printf("Enter number: ");
    scanf("%u", &num);

    // Binary
    int i = 7;
    while (i >= 0) {
        // Move the bit we want to the bottom end.
        uint8_t bit = num >> i;
        // Only check the bit at the end
        if (bit & 1) {
            printf("1");
        } else {
            printf("0");
        }
        // Shorter way of doing the same thing:
        // printf("%d", bit & 1);
        i--;
    }

    printf("\n");

    // Octal
    i = 6;
    while (i >= 0) {
        // Move the bit we want to the bottom end.
        uint8_t octal_digit = num >> i;
        // Only the last octal digit (i.e.
        // the last three bits).
        octal_digit = octal_digit & 7;

        // Shorter way of doing the same thing:
        printf("%d", octal_digit);

        i -= 3;
    }

    printf("\n");

    // Similar approach to above can be used for hexadecimal numbers.
    // However, you can also just use printf if you're allowed to.
    printf("%X\n", num);
    return 0;
}

/*
0001 1000: device |
0000 0001: 1
-----------
0001 1001

device = device | READING | WRITING | AS_BYTES;
*/
