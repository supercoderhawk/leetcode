# -*- coding: UTF-8 -*-
from typing import List
from collections import Counter


class Solution_161_170(object):
    def majorityElement(self, nums: List[int]) -> int:
        """
        169
        :param nums:
        :return:
        """
        return Counter(nums).most_common(1)[0][0]
