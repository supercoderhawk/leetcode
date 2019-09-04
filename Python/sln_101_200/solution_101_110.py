# -*- coding: utf-8 -*-
import math
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution_101_110(object):
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        """
        102
        :param root:
        :return:
        """
        results = []

        def recursive_tree(level, node):
            if not node:
                return
            if len(results) == level:
                level_list = [node.val]
                results.append(level_list)
            else:
                results[level].append(node.val)

            recursive_tree(level + 1, node.left)
            recursive_tree(level + 1, node.right)

        recursive_tree(0, root)
        return results

    def maxDepth(self, root):
        """
        104
        :return:
        """

        if not root:
            return 0

        left_depth = self.maxDepth(root.left) + 1
        right_depth = self.maxDepth(root.right) + 1

        return left_depth if left_depth > right_depth else right_depth
