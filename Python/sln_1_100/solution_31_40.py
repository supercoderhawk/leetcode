# -*- coding: UTF-8 -*-

class Solution_31_40:
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
