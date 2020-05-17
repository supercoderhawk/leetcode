# -*- coding: utf-8 -*-
import math
from typing import List
from common_utils import ListNode


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

    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        """
        103
        :param root:
        :return:
        """
        if not root:
            return []
        node_list = [root]
        next_node_list = []
        zigzag_list = []
        idx = 0

        while node_list:
            zigzag = []
            for node in node_list:
                if idx//2:
                    zigzag.append(node.val)
                else:
                    zigzag.insert(0, node.val)
                if node.left:
                    next_node_list.append(node.left)
                if node.right:
                    next_node_list.append(node.right)

            node_list = next_node_list
            next_node_list = []
            zigzag_list.append(zigzag)
            idx += 1

        return zigzag_list

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

    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
        """
        107
        :param root:
        :return:
        """

    def sortedListToBST(self, head: ListNode) -> TreeNode:
        """
        109
        :param head:
        :return:
        """
        if not head:
            return None
        mid_node = self.get_mid(head)
        mid = TreeNode(mid_node.val)

        if mid_node == head:
            return mid

        mid.left = self.sortedListToBST(head)
        mid.right = self.sortedListToBST(mid_node.next)
        return mid

    def get_mid(self, head:ListNode):
        prev_ptr = None
        slow_node = fast_node = head

        while fast_node and fast_node.next:
            prev_ptr = slow_node
            slow_node = slow_node.next
            fast_node = fast_node.next.next
        if prev_ptr:
            prev_ptr.next = None
        return slow_node

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