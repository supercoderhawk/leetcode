/*
 * Given an integer n, return the number of trailing zeroes in n!.
 * Note: Your solution should be in logarithmic time complexity.
 * Created by supercoderhawk on 2017/7/26.
 */
#include <stdio.h>

int trailingZeroes(int n) {
    if (n <= 0)
        return 0;

    int count = 0;
    for (long long i = 5; i<=n; i *= 5) {
        count += n / i;
    }
    return count;
}

void testTrailingZeroes() {
    printf("%d", trailingZeroes(25));
}