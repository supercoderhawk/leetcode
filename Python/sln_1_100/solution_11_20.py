# -*- coding: utf-8 -*-
from collections import OrderedDict
from typing import List


class Solution_11_20(object):
    def intToRoman(self, num):
        """
        12
        :param num:
        :return:
        """
        num2roman = {1: 'I', 5: 'V', 10: 'X', 50: 'L', 100: 'C', 500: 'D', 1000: 'M'}
        rets = ['I', 'V', 'X', 'L', 'C', 'D', 'M']
        for n in num2roman:
            num

    def threeSumClosest(self, nums: List[int], target: int) -> int:
        """
        16
        :param nums:
        :param target:
        :return:
        """
        if len(nums) == 3:
            return sum(nums)
        nums = sorted(nums)

        if sum(nums[:3]) >= target:
            return sum(nums[:3])
        if sum(nums[-3:]) <= target:
            return sum(nums[-3:])
        min_diff = sum(nums[:3])-target
        for i in range(len(nums) - 2):
            j = i + 1
            k = len(nums) - 1
            while j < k:
                diff = nums[i] + nums[j] + nums[k] - target
                if diff < 0:
                    j += 1
                elif diff > 0:
                    k -= 1
                else:
                    return target
                if abs(diff) < abs(min_diff):
                    min_diff = diff

        return min_diff + target
