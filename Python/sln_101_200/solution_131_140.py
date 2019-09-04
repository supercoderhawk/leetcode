# -*- coding: utf-8 -*-
from typing import List


class Solution_131_140:
    def partition(self, s: str) -> List[List[str]]:
        """
        131
        :param s:
        :return:
        """
        results = []

        def partition_substring(arr, rest_s):
            if not rest_s:
                results.append(arr)
            for i in range(1, len(rest_s) + 1):
                sub_s = rest_s[:i]

                part_len = i // 2
                if not part_len or sub_s[:part_len] == sub_s[-part_len:][::-1]:
                    partition_substring(arr + [sub_s], rest_s[i:])

        partition_substring([], s)
        return results

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
