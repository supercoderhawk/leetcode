# -*- coding: utf-8 -*-
from typing import List
from common_utils import *


class Solution_141_150(object):
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        """
        144
        :param root:
        :return:
        """
        results = []

        def traversal(node):
            if not node:
                return
            results.append(node.val)
            traversal(node.left)
            traversal(node.right)

        traversal(root)
        return results
