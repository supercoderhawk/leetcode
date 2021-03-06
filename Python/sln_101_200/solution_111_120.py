# -*- coding: utf-8 -*-
import copy
from typing import List
from common_utils import *


class Solution_111_120(object):
    def minDepth(self, root: TreeNode) -> int:
        """
        111
        :param root:
        :return:
        """
        if not root:
            return 0
        if root.left and root.right:
            left_depth = self.minDepth(root.left)
            right_depth = self.minDepth(root.right)
            return min(left_depth, right_depth) + 1
        elif not root.left and not root.right:
            return 1
        elif not root.right:
            return self.minDepth(root.left) + 1
        else:
            return self.minDepth(root.right) + 1

    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        """
        113
        :param root:
        :param sum:
        :return:
        """
        path_list = []

        def check_sum(node, val, path):
            if not node:
                return
            if node and node.left is None and node.right is None:
                if val+node.val == sum:
                    path.append(node.val)
                    path_list.append(path)
                return
            path.append(node.val)
            check_sum(node.left, val + node.val, copy.deepcopy(path))
            check_sum(node.right, val + node.val, copy.deepcopy(path))

        check_sum(root, 0, [])
        return path_list

    def generate(self, numRows: int) -> List[List[int]]:
        """
        118
        :param numRows:
        :return:
        """
        if numRows == 0:
            return []
        elif numRows == 1:
            return [[1]]
        elif numRows == 2:
            return [[1], [1, 1]]

        results = [[1], [1, 1]]
        for i in range(2, numRows):
            row = [1]
            for j in range(1, i):
                row.append(results[i - 1][j - 1] + results[i - 1][j])
            row.append(1)
            results.append(row)
        return results

    def getRow(self, rowIndex: int) -> List[int]:
        """
        118
        :param rowIndex:
        :return:
        """
        if rowIndex == 0:
            return [1]
        elif rowIndex == 1:
            return [1, 1]
        last_row = [1, 1]
        for row in range(2, rowIndex + 1):
            current_row = [1]
            for j in range(1, row):
                current_row.append(last_row[j - 1] + last_row[j])
            current_row.append(1)
            last_row = current_row
        return last_row

    def minimumTotal(self, triangle: List[List[int]]) -> int:
        """
        120
        :param triangle:
        :return:
        """
        if len(triangle) == 1:
            return triangle[0][0]

        min_sum_list = [triangle[0][0]]
        for row in triangle[1:]:
            new_min_sum_list = [row[0] + min_sum_list[0]]
            for idx, num in enumerate(row[1:], 1):
                if idx < len(row) - 1:
                    min_sum = min(min_sum_list[idx - 1], min_sum_list[idx]) + num
                else:
                    min_sum = min_sum_list[idx - 1] + num
                new_min_sum_list.append(min_sum)
            min_sum_list = new_min_sum_list
        return min(min_sum_list)
