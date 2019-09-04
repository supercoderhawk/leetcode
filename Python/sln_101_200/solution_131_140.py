# -*- coding: utf-8 -*-
from typing import List


class Solution_131_140:
    def singleNumber(self, nums):
        """
        136
        :param nums:
        :return:
        """
        val = {}
        for num in nums:
            if num not in val:
                val[num] = 1
            else:
                val.pop(num)
        return list(val.keys())[0]

    def singleNumber_2(self, nums: List[int]) -> int:
        """
        137
        :param nums:
        :return:
        """
        return (sum(set(nums)) * 3 - sum(nums)) // 2
