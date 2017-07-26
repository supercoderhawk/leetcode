/*
 * Created by supercoderhawk on 2017/7/19.
 * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 *
 * For example:
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 */
#include <stdio.h>
#include <math.h>

int countDigitOne(int n) {
    if (n < 0)
        return 0;
    int count = 0, maxPart = 0, minPart = 0, tmp = 0;
    long long divider = 0;
    for (long long i = 1; i <= n; i *= 10) {
        divider = i * 10;
        tmp = n % divider - i + 1;
        maxPart = tmp > 0 ? tmp : 0;
        minPart = maxPart > i ? i : maxPart;
        count += (n / divider) * i + minPart;
    }

    return count;
}

void testCountDigitOne() {
    printf("%d", countDigitOne(1));
}