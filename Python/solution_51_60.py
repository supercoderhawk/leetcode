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
