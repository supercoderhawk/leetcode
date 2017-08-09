package com.supercoderhawk;


import org.junit.Before;
import org.junit.Test;
import com.supercoderhawk.Solution_1_10;

import static org.junit.Assert.*;

public class Solution_1_10Test {
  private Solution_1_10 solution = new Solution_1_10();

  @Test
  public void twoSum() throws Exception {
  }

  @Test
  public void findMedianSortedArrays() throws Exception {
    int[] a1={1},a2={2,3};
    assertEquals(2.0,solution.findMedianSortedArrays(a1,a2),0.0);
    assertEquals(1.0,solution.findMedianSortedArrays(new int[]{1},new int[]{}),0.0);
    assertEquals(1.5,solution.findMedianSortedArrays(new int[]{1},new int[]{2}),0.0);
    assertEquals(3.0,solution.findMedianSortedArrays(new int[]{1},new int[]{2,3,4,5}),0.0);
    assertEquals(4.0,solution.findMedianSortedArrays(new int[]{5,6},new int[]{1,2,3,4,7}),0.0);
  }

}