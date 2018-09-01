# -*- coding: UTF-8 -*-

class Solution_51_60:
    def spiralOrder(self, matrix):
        """
        problem 54 - Spiral Matrix
        Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

        For example,
        Given the following matrix:

        [
         [ 1, 2, 3 ],
         [ 4, 5, 6 ],
         [ 7, 8, 9 ]
        ]
        You should return [1,2,3,6,9,8,7,4,5].
        :type matrix: List[List[int]]
        :rtype: List[int]
        """

        res = []

        if len(matrix) == 0:
            return res
        if len(matrix[0]) == 0:
            return res

        direction = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        x, y = 0, -1
        step = [len(matrix[0]), len(matrix) - 1]
        curr_direction = 0

        while step[curr_direction % 2] != 0:
            for i in range(step[curr_direction % 2]):
                x += direction[curr_direction][0]
                y += direction[curr_direction][1]
                res.append(matrix[x][y])

            step[curr_direction % 2] -= 1
            curr_direction = (curr_direction + 1) % 4

        return res

    def lengthOfLastWord(self, s):
        """
        58
        :type s: str
        :rtype: int
        """
        if len(s) <= 1:
            if not s or s == ' ':
                return 0
            else:
                return 1
        start = end = len(s)
        index = len(s) - 2
        last_ch = s[-1]
        while index >= 0:
            cur_ch = s[index]
            if last_ch == ' ' and cur_ch != ' ':
                end = index + 1
            elif cur_ch == ' ' and last_ch != ' ':
                start = index + 1
                break
            if index == 0 and cur_ch != ' ':
                start = index
            last_ch = cur_ch
            index -= 1
        return end - start
