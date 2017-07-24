/*
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 * Created by supercoderhawk on 2017/7/23.
 */

#include <math.h>
#include <stdio.h>

int reverse(int x) {
    long long maxInt = (long) pow(2, 31), result = 0;
    int num = x, length = 0;
    while (num != 0) {
        num /= 10;
        length += 1;
    }
    num = x;
    for (int i = length - 1; i >= 0; i--) {
        result = result * 10 + (num % 10);
        num /= 10;
    }
    if (result > maxInt || result < -maxInt - 1)
        result = 0;

    return (int) result;
}

void testReverse() {
    printf("%d", reverse(123));
    printf("%d", reverse(-2147483648));
}
