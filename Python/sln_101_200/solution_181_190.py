# -*- coding: UTF-8 -*-
from typing import List


class Solution_181_190(object):
    def rotate(self, nums: List[int], k: int) -> None:
        """
        189
        :param nums:
        :param k:
        :return:
        """
        k = k % len(nums)
        nums[:] = nums[-k:] + nums[:-k]
