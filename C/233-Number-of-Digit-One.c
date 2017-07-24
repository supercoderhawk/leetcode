//
// Created by supercoderhawk on 2017/7/19.
//

/*
 * Given an integer n, count the total number of digit 1 appearing in all non-negative integers less than or equal to n.
 *
 * For example:
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 */

int countDigitOne(int n) {
    int count = 0,digitsCount = 1,nClone = n;
    while(nClone >= 10){
        digitsCount += 1;
        nClone/=10;
    }
    nClone = n;
    int digits[digitsCount];
    for(int i = digitsCount-1;i>=0;i--)
    {
        digits[i] = nClone%10;
        nClone /= 10;
    }
    return 0 ;

}