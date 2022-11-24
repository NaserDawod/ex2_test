#include <stdio.h>

#define HEXA_BASE 16
#define DECIMAL_BASE 10
#define OCTAL_BASE 8

int pow2(int x, int y) {
    int s = 1;
    while (y > 0) {
        s *= x;
        --y;
    }
    return s;
}

int main() {
    int choice;
    int oct;
    int checkValidNumber;
    int checkValid;
    int copy;
    int sizeH;
    unsigned long long num1, num2, checkValidUnsigned;
    unsigned long long num1Copy, num2Copy;
    int numLen = 0;
    int binNum;
    do {
        printf("Choose an option:\n"
               "1. octal to hex\n"
               "2. binary addition\n"
               "3. print HI\n"
               "4. count bits\n"
               "5. decimal to binary\n"
               "6. Zig-Zag bits\n"
               "7. exit\n");
        scanf(" %d", &choice);
        switch (choice) {
            case 1:
                printf("Please enter number in octal base: ");
                scanf(" %d", &oct);
                checkValidNumber = oct;
                checkValid = 1;
                while (checkValidNumber != 0) { /* check if the number is unValid */
                    if (checkValidNumber % DECIMAL_BASE > 7 || checkValidNumber % DECIMAL_BASE < 0) {
                        checkValid = 0;
                        break;
                    }
                    checkValidNumber /= DECIMAL_BASE;
                }
                if (checkValid) { /* if the number is valid then do the math(convert from octal to decimal then hexa) */
                    if (oct == 0) {
                        printf("0\n");
                        continue;
                    }
                    copy = oct;
                    numLen = 0;
                    int decimalNum = 0;
                    while (copy > 0){ /* first find the number of digits because the number is reversed
                                        * And we need to find the right index of each number */
                        numLen++;
                        copy /= DECIMAL_BASE;
                    }
                    for (int i = numLen - 1; i >= 0; --i, oct /= DECIMAL_BASE) { /* convert the number from octal to decimal */
                        decimalNum += oct % DECIMAL_BASE * (pow2(OCTAL_BASE, i));
                    }
                    numLen = 0;
                    copy = decimalNum;
                    while (copy > 0) { /* find the length of the decimal number in order to print it reversed order */
                        numLen++;
                        copy /= HEXA_BASE;
                    }
                    int divReminder = 0;
                    for (int i = 0; i < numLen; ++i) {
                        copy = decimalNum;
                        for (int j = 0; j < numLen - i; ++j, copy /= HEXA_BASE) {
                            divReminder = copy % HEXA_BASE; /* find the last digit and print it first */
                        }
                        printf("%X", divReminder);
                    }
                    printf("\n");
                } else {
                    printf("Invalid input!\n");
                }
                break;
            case 2:
                printf("Please enter two binary numbers: ");
                scanf(" %llu %llu", &num1, &num2);
                if (num1 == 0 && num2 == 0) {
                    printf("0 + 0 = 0\n");
                    break;
                }
                checkValidUnsigned = num1;
                checkValid = 1;
                while (checkValidUnsigned != 0) { /* scan the first number to check if all the digits are 0/1 (valid)*/
                    if (checkValidUnsigned % DECIMAL_BASE != 0 && checkValidUnsigned % DECIMAL_BASE != 1) {
                        checkValid = 0;
                        break;
                    }
                    checkValidUnsigned /= DECIMAL_BASE;
                }
                if (checkValid == 0){
                    printf("Invalid input!\n");
                    break;
                }
                checkValidUnsigned = num2;
                checkValid = 1;
                while (checkValidUnsigned != 0) { /* scan the second number to check if all the digits are 0/1 (valid)*/
                    if (checkValidUnsigned % DECIMAL_BASE != 0 && checkValidUnsigned % DECIMAL_BASE != 1) {
                        checkValid = 0;
                        break;
                    }
                    checkValidUnsigned /= DECIMAL_BASE;
                }
                if (checkValid == 0){
                    printf("Invalid input!\n");
                    break;
                }
                num1Copy = num1;
                num2Copy = num2;
                int num1Len = 0, num2Len = 0;
                while (num1Copy != 0){
                    num1Len++;
                    num1Copy /= DECIMAL_BASE;
                }
                while (num2Copy != 0){
                    num2Len++;
                    num2Copy /= DECIMAL_BASE;
                }
                unsigned long long sum = 0, rem = 0;
                unsigned long long i = 1;
                num1Copy = num1;
                num2Copy = num2;
                for (i = 1; num1 != 0 || num2 != 0; i *= 10, num1 /= DECIMAL_BASE, num2 /= DECIMAL_BASE) {
                    if ((num1 % 10 + num2 % 10 == 2 && rem == 0) || (num1 % 10 + num2 % 10 == 1 && rem == 1)) {
                        rem = 1;
                    } else if ((num1 % 10 + num2 % 10 == 1 && rem == 0) || (num1 % 10 + num2 % 10 == 0 && rem == 1)) {
                        sum += i;
                        rem = 0;
                    } else if (num1 % 10 + num2 % 10 == 2 && rem == 1) {
                        sum += i;
                        rem = 1;
                    } else {
                        rem = 0;
                    }
                }
                if (rem == 1) {
                    sum += i;
                }
                if (num1Len > num2Len){
                    while (num1Len > num2Len) {
                        num2Len++;
                        printf("0");
                    }
                    if (num2Copy != 0)
                        printf("%llu", num2Copy);
                    printf(" + ");
                    printf("%llu", num1Copy);
                    printf(" = ");
                } else {
                    while (num1Len < num2Len) {
                        num1Len++;
                        printf("0");
                    }
                    if (num1Copy != 0)
                        printf("%llu", num1Copy);
                    printf(" + ");
                    printf("%llu = ", num2Copy);
                }
                printf("%llu\n", sum);
                break;
            case 3:
                printf("Please enter size: ");
                scanf(" %d", &sizeH);
                if (sizeH < 1) {
                    printf("Invalid input!\n");
                    break;
                }
                int width = 4*sizeH + 8;
                int hight = 3*sizeH + 4;
                for (int i = 1; i <= hight; ++i) {
                    for (int j = 1; j <= width; ++j) {
                        if (j == 3*sizeH + 6 || (j > sizeH + 2 && j < 2*sizeH + 4 && (i < sizeH + 2 || i > 2*sizeH + 3))) {
                            printf(" ");
                        } else if ((i == 1 || i == hight)
                                   || ((i == sizeH + 2 || i == 2*sizeH + 3) && j > sizeH + 1 && j < 2*sizeH + 5)) {
                            printf("#");
                        } else if ((j == 1 || j == sizeH + 2 || j == 2*sizeH + 4 || j == 3*sizeH + 5 || j == 3*sizeH + 7 || j == width)
                                   && (i < sizeH + 2 || i > 2*sizeH + 3)) {
                            printf("#");
                        } else if ((j == 1 || j == 3*sizeH + 5 || j == 3*sizeH + 7 || j == width)){
                            printf("#");
                        } else {
                            printf("*");
                        }
                    }
                    printf("\n");
                }
                break;
            case 4:
                printf("Please enter a binary number: ");
                scanf(" %d", &binNum);
                checkValid = 1;
                checkValidNumber = binNum;
                while (checkValidNumber != 0) {
                    if (checkValidNumber % DECIMAL_BASE != 0 && checkValidNumber % DECIMAL_BASE != 1) {
                        checkValid = 0;
                        break;
                    }
                    checkValidNumber /= DECIMAL_BASE;
                }
                if (checkValid == 0) {
                    printf("Invalid input!\n");
                    break;
                }
                int count = 0;
                while (binNum != 0) {
                    count += binNum % DECIMAL_BASE;
                    binNum /= DECIMAL_BASE;
                }
                printf("%d\n", count);
                break;
            case 5:
                printf("Enter a non negative decimal number: ");
                scanf(" %d", &binNum);
                if (binNum < 0) {
                    printf("Invalid input!\n");
                    break;
                }
                printf("%d => ", binNum);
                if (binNum == 0) {
                    printf("0\n");
                    break;
                }
                unsigned int left_mask = 0b10000000000000000000000000000000;
                while (left_mask != 0) {
                    if (binNum & left_mask) {
                        break;
                    }
                    left_mask >>= 1;
                }
                while (left_mask != 0) {
                    printf("%d", (binNum & left_mask) != 0);
                    left_mask >>= 1;
                }
                printf("\n");
                break;
            case 6:
                printf("Enter a non negative decimal number: ");
                scanf(" %d", &binNum);
                if (binNum < 0) {
                    printf("Invalid input!\n");
                }
                int previosDigit = binNum & 1;
                int currDigit;
                checkValid = 1;
                binNum >>= 1;
                while (binNum != 0) {
                    currDigit = binNum & 1;
                    if (previosDigit == currDigit) {
                        checkValid = 0;
                        break;
                    }
                    previosDigit = currDigit;
                    binNum >>= 1;
                }
                if (checkValid) {
                    printf("true\n");
                } else {
                    printf("false\n");
                }
                break;
            case 7:
                printf("Bey!");
                break;
            default:
                printf("Invalid option!\n");
        }
    } while (choice != 7);
    return 0;
}

