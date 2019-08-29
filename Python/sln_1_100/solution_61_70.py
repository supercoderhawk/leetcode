# -*- coding: utf-8 -*-
from typing import *
from common_utils import *


class Solution_61_70(object):
    def rotateRight(self, head, k):
        """
        61
        :param head:
        :param k:
        :return:
        """
        if not head or not head.next:
            return head

        list_len = 1

        node = head
        while node.next:
            list_len += 1
            node = node.next
        last_node = node
        node = head.next
        prev_node = head
        if k % list_len == 0:
            new_head = head
        else:
            for _ in range(list_len - k % list_len - 1):
                prev_node = prev_node.next
                node = node.next
            new_head = node
            prev_node.next = None
            last_node.next = head
        return new_head

    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        """
        63
        :param obstacleGrid:
        :return:
        """
        if not obstacleGrid or not obstacleGrid[0]:
            return 0

        horizon_len = len(obstacleGrid)
        vertical_len = len(obstacleGrid[0])

        obstacleMatrix = [[0 for j in range(vertical_len)] for i in range(horizon_len)]
        if obstacleGrid[0][0] == 1:
            return 0
        obstacleMatrix[0][0] = 1
        for i in range(horizon_len):
            for j in range(vertical_len):
                if i == 0 and j == 0:
                    continue
                count = 0
                if obstacleGrid[i][j] == 0:
                    if i:
                        count += obstacleMatrix[i - 1][j]
                    if j:
                        count += obstacleMatrix[i][j - 1]
                obstacleMatrix[i][j] = count
        return obstacleMatrix[-1][-1]

    def minPathSum(self, grid: List[List[int]]) -> int:
        """
        64
        :param grid:
        :return:
        """
        if not grid or not grid[0]:
            return 0
        if len(grid) == 1:
            return sum(grid[0])
        if len(grid[0]) == 1:
            return sum(i[0] for i in grid)
        min_sum = [[-1] * len(grid[0]) for i in range(len(grid))]
        min_sum[0][0] = grid[0][0]
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if i == 0 and j == 0:
                    continue
                if i == 0:
                    min_sum[i][j] = grid[i][j] + min_sum[i][j - 1]
                elif j == 0:
                    min_sum[i][j] = grid[i][j] + min_sum[i - 1][j]
                else:
                    min_sum[i][j] = min(min_sum[i][j - 1], min_sum[i - 1][j]) + grid[i][j]
        return min_sum[len(grid)-1][len(grid[0])-1]


    def addBinary(self, a, b):
        """
        67
        :type a: str
        :type b: str
        :rtype: str
        """
        if len(a) > len(b):
            max_len = len(a)
            b = '0' * (len(a) - len(b)) + b
        else:
            max_len = len(b)
            a = '0' * (len(b) - len(a)) + a

        result = []
        carry = 0
        for ch_a, ch_b in zip(a[::-1], b[::-1]):
            bit = int(ch_a) + int(ch_b) + carry
            if bit > 1:
                result.append(str(bit - 2))
                carry = 1
            else:
                result.append(str(bit))
                carry = 0

        if carry == 1:
            result.append('1')

        return ''.join(result[::-1])
