/*
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * Note: You may not slant the container and n is at least 2.
 * Created by supercoderhawk on 2017/7/26.
 */
#include <stdio.h>

int maxArea(int *height, int heightSize) {
    int low = 0, high = heightSize - 1, max = 0, h = 0, area;
    while (low < high) {
        h = height[low] < height[high] ? height[low] : height[high];
        area = h * (high - low);
        if (area > max)
            max = area;
        if (height[low] < height[high])
            low++;
        else
            high--;
    }
    return max;
}

void testMaxArea() {
    int a[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d", maxArea(a, 9));
}