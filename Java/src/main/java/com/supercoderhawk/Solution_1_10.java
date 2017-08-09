package com.supercoderhawk;

public class Solution_1_10 {
  /**
   * problem 1
   *
   * @param nums:   输入数组
   * @param target: 目标和
   * @return: 目标和的索引数组
   */
  public int[] twoSum(int[] nums, int target) {
    return new int[]{1, 2};
  }

  public double findMedianSortedArrays(int[] nums1, int[] nums2) {
    if(nums1.length == 0){
      if(nums2.length % 2 == 0){
        return (nums2[nums2.length/2]+nums2[nums2.length/2-1])/2.0;
      }else{
        return nums2[nums2.length/2];
      }
    }else if(nums2.length == 0){
      if(nums1.length % 2 == 0){
        return (nums1[nums1.length/2]+nums1[nums1.length/2-1])/2.0;
      }else{
        return nums1[nums1.length/2];
      }
    }

    int[] A = nums1, B = nums2;
    double median = 0.0, maxLeft = 0.0, minRight = 0.0;
    if (nums1.length > nums2.length) {
      A = nums2;
      B = nums1;
    }
    int imin = 0, imax = A.length, i, j, halfLength = (A.length + B.length + 1) / 2;
    while (imin <= imax) {
      i = (imin + imax) / 2;
      j = halfLength - i;
      if (i < A.length && B[j - 1] > A[i]) {
        imin = i + 1;
      } else if (i > 0  && A[i - 1] > B[j]) {
        imax = i - 1;
      } else {
        if (i == 0) {
          maxLeft = B[j - 1];
        } else if (j == 0) {
          maxLeft = A[i - 1];
        } else {
          maxLeft = A[i - 1] > B[j - 1] ? A[i - 1] : B[j - 1];
        }

        if (i == A.length) {
          minRight = B[j];
        } else if (j == B.length) {
          minRight = A[i];
        } else {
          minRight = A[i] < B[j] ? A[i] : B[j];
        }

        if ((A.length + B.length) % 2 == 1)
          median = maxLeft;
        else
          median = (maxLeft + minRight) / 2;

        break;
      }
    }
    return median;
  }
}
