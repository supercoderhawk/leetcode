# -*- coding: utf-8 -*-
from typing import List


class Solution_211_220(object):
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        """
        219
        :param nums:
        :param k:
        :return:
        """
        num2idx = {}
        for idx, num in enumerate(nums):
            if num in num2idx and idx - num2idx[num] <= k:
                return True
            num2idx[num] = idx

        return False
