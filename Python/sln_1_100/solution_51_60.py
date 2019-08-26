# -*- coding: UTF-8 -*-
from itertools import permutations
from common_utils import Interval


class Solution_51_60:
    def solveNQueens(self, n):
        """
        51
        :type n: int
        :rtype: List[List[str]]
        """
        outputs = []
        for candidate in permutations(range(0, n)):
            left_triangle = {v - i for i, v in enumerate(candidate)}
            right_triangle = {v + i for i, v in enumerate(candidate)}
            if len(left_triangle) == len(right_triangle) == n:
                output = []
                for queen in candidate:
                    output.append('.' * queen + 'Q' + '.' * (n - 1 - queen))
                outputs.append(output)
        return outputs

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

    def merge(self, intervals):
        """
        56
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        intervals = sorted(intervals, key=lambda i: i.start)
        new_intervals = []
        last_end = -1
        last_start = -1
        for iterval in intervals:
            start, end = iterval.start, iterval.end
            if new_intervals and last_end >= start:
                new_start = start if start < last_start else last_start
                new_end = end if end > last_end else last_end
                new_intervals.pop(-1)
                start, end = new_start, new_end
            new_intervals.append(Interval(start, end))
            last_start, last_end = start, end
        return new_intervals

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

    def generateMatrix(self, n):
        """
        59
        :param n:
        :return:
        """
        x, y = 0, -1
        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        steps = [n, n - 1]

        val = 1
        matrix = [[0] * n for _ in range(n)]
        direction_index = 0

        while steps[direction_index % 2]:
            curr_direction = directions[direction_index]
            for _ in range(steps[direction_index % 2]):
                x += curr_direction[0]
                y += curr_direction[1]
                matrix[x][y] = val
                val += 1
            steps[direction_index % 2] -= 1
            direction_index = (direction_index + 1) % 4

        return matrix

    def getPermutation(self, n, k):
        """
        60
        :param n:
        :param k:
        :return:
        """
        factorial = 1
        for i in range(1, n + 1):
            factorial *= i
        digits = [str(d) for d in range(1, n + 1)]
        perm_digits = []
        for index in range(n, 0, -1):
            current_digit = (k - 1) // (factorial // index) + 1
            if current_digit:
                k = (k - 1) % (factorial // index) + 1
                factorial //= index
                perm_digits.append(digits.pop(current_digit - 1))
            else:
                perm_digits += digits
                break

        return ''.join(perm_digits)
