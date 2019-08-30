# -*- coding: utf-8 -*-
from typing import List


class Solution_111_120(object):
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
