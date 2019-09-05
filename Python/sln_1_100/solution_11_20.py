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
        roman2num = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        roman_digits = ['I', 'V', 'X', 'L', 'C', 'D', 'M']
        s = ''
        for idx, roman_digit in enumerate(roman_digits[::-1], 1):
            idx = len(roman_digits) - idx
            if num <= 0:
                break

            digit = num // roman2num[roman_digit]
            if digit:
                if idx < len(roman_digits) - 1:
                    if idx > 0 and idx % 2 and (num + roman2num[roman_digits[idx - 1]]) // roman2num[
                        roman_digits[idx + 1]] == 1:
                        s += roman_digits[idx - 1] + roman_digits[idx + 1]
                        num -= roman2num[roman_digits[idx + 1]] - roman2num[roman_digits[idx - 1]]
                    elif (idx + 1) % 2 and (num + roman2num[roman_digit]) // roman2num[roman_digits[idx + 1]] == 1:
                        s += roman_digits[idx] + roman_digits[idx + 1]
                        num -= roman2num[roman_digits[idx + 1]] - roman2num[roman_digit]
                    else:
                        s += roman_digits[idx] * digit
                        num -= digit * roman2num[roman_digits[idx]]
                else:
                    s += roman_digits[idx] * digit
                    num -= digit * roman2num[roman_digits[idx]]
        return s

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
        min_diff = sum(nums[:3]) - target
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
