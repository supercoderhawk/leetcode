# -*- coding: utf-8 -*-
from typing import List


class Solution_121_130(object):
    def maxProfit(self, prices: List[int]) -> int:
        """
        121
        :param prices:
        :return:
        """
        if len(prices) <= 1:
            return 0
        max_profit = prices[1] - prices[0]
        lowest_profit = prices[0]
        for price in prices[1:]:
            if price < lowest_profit:
                lowest_profit = price
            if price - lowest_profit > max_profit:
                max_profit = price-lowest_profit
        return max_profit
