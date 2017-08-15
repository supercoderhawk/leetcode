/*
 * Implement pow(x, n).
 * Created by supercoderx on 2017/8/15.
 */
#include <stdio.h>
#include <limits.h>

double myPow(double x, int n) {
    if (x == 0)
        return 0;
    if (n == 0)
        return 1;
    int index = n / 2;
    if (n < 0) {
        x = 1 / x;
        index *= -1;
    }
    double y = x * x;

    return n % 2 == 0 ? myPow(y, index) : x * myPow(y, index);
}

void testMyPow() {
    printf("%lf", myPow(22.14659, -2));
    printf("%lf", myPow(2.00000, -2147483648));
}
