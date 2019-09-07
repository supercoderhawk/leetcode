# -*- coding: utf-8 -*-
import math
from typing import List


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution_101_110(object):
    def is_mirror(self, node1, node2):
        if not node1 and not node2:
            return True
        elif not node1 or not node2:
            return False
        else:
            node_judge = node1.val == node2.val
            left_judge = self.is_mirror(node1.left, node2.right)
            right_judge = self.is_mirror(node1.right, node2.left)
            return node_judge and left_judge and right_judge

    def isSymmetric(self, root: TreeNode) -> bool:
        """
        101
        :param root:
        :return:
        """
        if not root:
            return True
        return self.is_mirror(root, root)

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

    def isBalanced(self, root: TreeNode) -> bool:
        """
        110
        :param root:
        :return:
        """
        if not root:
            return True

        def is_sub_tree_balanced(node):
            if not node:
                return True
            is_left_balanced = is_sub_tree_balanced(node.left)
            is_right_balanced = is_sub_tree_balanced(node.right)
            if not is_left_balanced or not is_right_balanced:
                return False
            left_depth = self.maxDepth(node.left)
            right_depth = self.maxDepth(node.right)
            if abs(left_depth - right_depth) <= 1:
                return True
            else:
                return False
        return is_sub_tree_balanced(root)