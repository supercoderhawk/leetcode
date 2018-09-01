# -*- coding: utf-8 -*-
import math
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution_101_110(object):
    def maxDepth(self, root):
        """
        104
        :return:
        """

        if not root:
            return 0

        left_depth = self.maxDepth(root.left)+1
        right_depth = self.maxDepth(root.right)+1

        return left_depth if left_depth>right_depth else right_depth
