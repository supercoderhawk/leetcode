/*
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

 * For example,
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 * Created by supercoderx on 2017/8/13.
 */
#include <stdio.h>

int trap(int *height, int heightSize) {
    if (heightSize < 2)
        return 0;
    int volume = 0, maxLeft, maxRight;
    for (int i = 0; i < heightSize; i++) {
        maxLeft = maxRight = height[i];
        for (int j = 0; j < i; j++) {
            if (height[j] > maxLeft)
                maxLeft = height[j];
        }
        for (int k = i + 1; k < heightSize; k++) {
            if (height[k] > maxRight)
                maxRight = height[k];
        }
        volume += (maxLeft < maxRight ? maxLeft : maxRight) - height[i];
    }
    return volume;
}

void testTrap() {
    int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int b[] = {5, 2, 1, 2, 1, 5};
    printf("%d\n", trap(b, sizeof(b) / sizeof(b[0])));
    printf("%d", trap(a, sizeof(a) / sizeof(a[0])));
}