/*
 * You are climbing a stair case. It takes n steps to reach to the top.

 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 * Note: Given n will be a positive integer.
 * Created by supercoderhawk on 2017/8/18.
 */
#include <stdio.h>
int climbStairs(int n) {
    if (n <= 1)
        return n;
    int curr_ways = 1, next_ways = 1;
    for (int i = 1; i <= n; ++i) {
        curr_ways = (next_ways += curr_ways) - curr_ways;
    }
    return curr_ways;
}

void testClimbStairs(){
printf("%d",climbStairs(2));
}