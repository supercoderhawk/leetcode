# -*- coding: utf-8 -*-
from typing import List


class Solution_291_300(object):
    def lengthOfLIS(self, nums: List[int]) -> int:
        """
        300
        :param nums:
        :return:
        """
        if len(nums) <= 1:
            return len(nums)
        max_len_arr = [1] * len(nums)
        arr_len = len(nums)
        for i in range(0, arr_len):
            max_len_i = max_len_arr[i]
            for j in range(0, i):
                if nums[j] < nums[i]:
                    max_len_j = max_len_arr[j] + 1
                    if max_len_j > max_len_i:
                        max_len_i = max_len_j
            max_len_arr[i] = max_len_i
        max_len = max(max_len_arr)
        return max_len
