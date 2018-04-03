/*
 * Implement int sqrt(int x).

 * Compute and return the square root of x.
 * Created by supercoderhawk on 2017/8/18.
 */
#include <stdio.h>
#include <limits.h>
int mySqrt(int x) {
    if(x == 0)
        return 0;
    int left = 0,right = INT_MAX,mid;
    while (1){
        mid = (left+right)/2;
        if(mid>x/mid){
            right = mid -1;
        }else{
            if(mid+1>x/(mid+1))
                return mid;
            left =  mid+1;
        }
    }
}

void testMySqrt(){
    printf("%d",mySqrt(0));
}