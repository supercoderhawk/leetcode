/*
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.

 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]

 * The median is 2.0
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]

 * The median is (2 + 3)/2 = 2.5
 * Created by supercoderx on 2017/8/8.
 */
#include <stdio.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size) {
    if(nums1Size == 0 ){
        return nums2Size%2==0?(nums2[nums2Size/2]+nums2[nums2Size/2-1])/2:nums2[nums2Size/2];
    }else if (nums2Size == 0){
        return nums1Size%2 == 0?(nums1[nums1Size/2]+nums1[nums1Size/2-1])/2:nums1[nums1Size/2];
    }

    int *pTmp, tmp, *A = nums1, *B = nums2;
    int imin = 0, imax = nums1Size, m = nums1Size, n = nums2Size;
    double median = 0.0,maxLeft = 0.0, minRight = 0.0;
    int i, j;

    if (n < m) {
        pTmp = A;
        A = B;
        B = pTmp;
        imax = n;
        tmp = m;
        m = n;
        n = tmp;
    }

    while (imin <= imax) {
        i = (imin + imax) / 2;
        j = (m + n + 1) / 2 - i;
        if (i < m && B[j - 1] > A[i]) {
            imin = i + 1;
        } else if (j > 0 && B[j] < A[i - 1]) {
            imax = i - 1;
        } else {
            if (i == 0)
                maxLeft = B[j - 1];
            else if (j == 0)
                maxLeft = A[i - 1];
            else
                maxLeft = A[i - 1] > B[j - 1] ? A[i - 1] : B[j - 1];

            if (i == m)
                minRight = B[j];
            else if (j == n)
                minRight = A[i];
            else
                minRight = A[i] < B[j] ? A[i] : B[j];

            if ((m + n) % 2 == 1)
                median = maxLeft;
            else
                median = (maxLeft + minRight) / 2;
            break;
        }
    }

    return median;
}

void testFindMedianSortedArrays() {
    int a[2] = {1, 3};
    int b[1] = {2};
    printf("%lf", findMedianSortedArrays(a, 2, b, 1));
}

