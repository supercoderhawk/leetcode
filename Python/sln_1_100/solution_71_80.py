# -*- coding: utf-8 -*-
from typing import List
import copy
import math


class Solution_71_80(object):
    def simplifyPath(self, path):
        """
        71
        :type path: str
        :rtype: str
        """
        if not path or path == '/':
            return path

        r_offset = 0
        while len(path) - 1 >= r_offset and path[len(path) - 1 - r_offset] == '/':
            r_offset += 1

        if r_offset:
            path = path[:-r_offset]

        if not path:
            return '/'

        path_segments = path[1:].split('/')
        final_path_segments = []

        for segment in path_segments:
            if segment == '..':
                if final_path_segments:
                    final_path_segments.pop()
            elif segment in {'.', ''}:
                continue
            else:
                final_path_segments.append(segment)

        return '/' + '/'.join(final_path_segments)

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        """
        74
        :param matrix:
        :param target:
        :return:
        """
        if not matrix:
            return False
        if not matrix[0]:
            return False
        row = len(matrix) - 1
        col = len(matrix[0]) - 1

        def binary_search(func, l):
            left = 0
            right = l
            if func(0) >= target:
                return 0
            elif func(l) <= target:
                return l
            else:
                mid = (left + right) // 2
                while left < mid:
                    mid_val = func(mid)
                    if mid_val < target:
                        left = mid
                    elif mid_val > target:
                        right = mid
                    else:
                        return mid
                    mid = (left + right) // 2

            return left

        row_index = binary_search(lambda i: matrix[i][0], row)
        if matrix[row_index][0] == target:
            return True
        col_index = binary_search(lambda i: matrix[row_index][i], col)
        if matrix[row_index][col_index] == target:
            return True
        return False

    def sortColors(self, nums: List[int]) -> None:
        """
        75
        Do not return anything, modify nums in-place instead.
        """
        prefix_idx = 0
        suffix_idx = len(nums) - 1
        idx = 0
        while idx <= suffix_idx:
            num = nums[idx]

            if num == 0 and idx > prefix_idx:
                nums[prefix_idx], nums[idx] = nums[idx], nums[prefix_idx]
                prefix_idx += 1
                idx -= 1
            elif num == 2 and idx < suffix_idx:
                nums[suffix_idx], nums[idx] = nums[idx], nums[suffix_idx]
                suffix_idx -= 1
                idx -= 1
            idx += 1

    def combine(self, n: int, k: int) -> List[List[int]]:
        """
        77
        :param n:
        :param k:
        :return:
        """

        results = []

        def backtrace(res=[]):
            if len(res) == k:
                results.append(res)
            else:
                if not res:
                    m = 1
                else:
                    m = res[-1] + 1
                for i in range(m, n + 1):
                    backtrace(res + [i])

        backtrace()
        return results
