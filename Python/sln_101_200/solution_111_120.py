# -*- coding: utf-8 -*-
from typing import List


class Solution_111_120(object):
    def generate(self, numRows: int) -> List[List[int]]:
        """
        118
        :param numRows:
        :return:
        """
        if numRows == 0:
            return []
        elif numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1], [1, 1]]

        results = [[1], [1, 1]]
        for i in range(2, numRows):
            row = [1]
            for j in range(1, i):
                row.append(results[i - 1][j - 1] + results[i - 1][j])
            row.append(1)
            results.append(row)
        return results

    def minimumTotal(self, triangle: List[List[int]]) -> int:
        """
        120
        :param triangle:
        :return:
        """
        if len(triangle) == 1:
            return triangle[0][0]

        min_sum_list = [triangle[0][0]]
        for row in triangle[1:]:
            new_min_sum_list = [row[0] + min_sum_list[0]]
            for idx, num in enumerate(row[1:], 1):
                if idx < len(row) - 1:
                    min_sum = min(min_sum_list[idx - 1], min_sum_list[idx]) + num
                else:
                    min_sum = min_sum_list[idx - 1] + num
                new_min_sum_list.append(min_sum)
            min_sum_list = new_min_sum_list
        return min(min_sum_list)
