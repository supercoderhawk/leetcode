# -*- coding: utf-8 -*-
from unittest import TestCase
from sln_1_100.solution_81_90 import *
from common_utils import *


class Test_Solution_81_90(TestCase):
    def setUp(self) -> None:
        self.sln = Solution_81_90()

    def test_partition(self):
        head = build_linked_list([1, 4, 3, 2, 5, 2])
        ret = self.sln.partition(head, 3)
        print_linked_list(ret)

    def test_merge(self):
        arr1 = [1, 2, 3, 0, 0, 0]
        self.sln.merge(arr1, 3, [2, 5, 6], 3)
        self.assertEqual(arr1, [1, 2, 2, 3, 5, 6])
        arr2 = [1]
        self.sln.merge(arr2, 1, [], 0)
        self.assertEqual(arr2, [1])
        arr3 = [2, 0]
        self.sln.merge(arr3, 1, [1], 1)
        self.assertEqual(arr3, [1, 2])
