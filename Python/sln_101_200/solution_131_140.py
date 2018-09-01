# -*- coding: utf-8 -*-

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
