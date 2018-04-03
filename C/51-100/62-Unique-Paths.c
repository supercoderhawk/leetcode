/*
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

 * How many possible unique paths are there?
 * Note: m and n will be at most 100.
 * Created by supercoderhawk on 2017/8/18.
 */
#include <stdio.h>
void trace(int x, int y,int m,int n, int *count){
    if(x == m && y == n){
        (*count)++;
        return;
    }
    if(x<m)
        trace(++x,y,m,n,count);
    if(y<n)
        trace(x,++y,m,n,count);
}

int uniquePaths(int m, int n) {
    /*int count = 0;
    trace(1,1,m,n,&count);
    return count;*/
    int grid[m][n];
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <n ; ++j) {
            if(i == 0 || j == 0)
                grid[i][j] = 1;
            else
                grid[i][j] = grid[i-1][j]+grid[i][j-1];
        }
    }
    return grid[m-1][n-1];
}

void testUniquePaths(){
    printf("%d",uniquePaths(3,3));
}
