/*
 * Divide two integers without using multiplication, division and mod operator.

 * If it is overflow, return MAX_INT.
 * Created by supercoderx on 2017/8/11.
 */
#include <stdio.h>
#include <limits.h>

int divide(int dividend, int divisor) {
    if (divisor == 0 || (dividend == INT_MIN) && (divisor == -1)) {
        return INT_MAX;
    }
    if (dividend == INT_MIN && divisor == 1)
        return INT_MIN;
    int neg = 0;
    if ((dividend > 0) ^ (divisor > 0)) {
        neg = 1;
    }
    long long dvd = dividend, dvs = divisor;
    if (dividend < 0) {
        dvd = -dvd;
    }
    if (divisor < 0) {
        dvs = -dvs;
    }


    int res = 0;
    while (dvd >= dvs) {
        long long temp = dvs, scala = 1;
        while (dvd >= (temp << 1)) {
            temp <<= 1;
            scala <<= 1;
        }
        dvd -= temp;
        res += scala;
    }
    return neg == 1 ? -res : res;
}

void testDivide() {
    printf("%d", divide(-2147483648, 2));
}