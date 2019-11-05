# -*- coding: UTF-8 -*-
from typing import List


class Solution_31_40:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        31
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) <= 1:
            return
        num_len = len(nums)
        if nums[num_len - 2] < nums[num_len - 1]:
            nums[num_len - 1], nums[num_len - 2] = nums[num_len - 2], nums[num_len - 1]
        else:
            start_idx = -1
            for idx in range(num_len - 1, 0, -1):
                if nums[idx - 1] < nums[idx]:
                    start_idx = idx - 1
                    break
            if start_idx == -1:
                for idx in range(0, num_len // 2):
                    nums[idx], nums[num_len - 1 - idx] = nums[num_len - 1 - idx], nums[idx]
            else:
                end_idx = num_len - 1
                for idx in range(start_idx + 1, num_len):
                    if nums[start_idx] >= nums[idx]:
                        end_idx = idx - 1
                        break
                nums[start_idx], nums[end_idx] = nums[end_idx], nums[start_idx]
                for idx in range(start_idx + 1, start_idx + 1 + (num_len - 1 - start_idx) // 2):
                    nums[idx], nums[num_len + start_idx - idx] = nums[num_len + start_idx - idx], nums[idx]

    def searchInsert(self, nums, target):
        """
        35
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        index = 0
        if len(nums) and nums[-1] < target:
            return len(nums)
        for idx, (prev, curr) in enumerate(zip(nums[:-1], nums[1:])):
            if prev < target <= curr:
                index = idx + 1
                break
            elif target < curr:
                break

        return index

    def countAndSay(self, n):
        """
        38
        :type n: int
        :rtype: str
        """
        curr = '1'
        for i in range(1, n):
            prev = curr
            curr = ''
            count = 1
            say = prev[0]
            for ch in prev[1:]:
                if say == ch:
                    count += 1
                else:
                    curr += str(count) + say
                    say = ch
                    count = 1
            curr += str(count) + say
        return curr

    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        """
        39
        :param candidates:
        :param target:
        :return:
        """
