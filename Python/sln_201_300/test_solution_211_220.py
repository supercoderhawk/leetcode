# -*- coding: utf-8 -*-
from unittest import TestCase
from sln_201_300.solution_211_220 import Solution_211_220


class Test_Solution_211_220(TestCase):
    def setUp(self) -> None:
        self.sln = Solution_211_220()

    def test_containsNearbyDuplicate(self):
        nums = [1, 2, 3, 1]
        self.assertEqual(self.sln.containsNearbyDuplicate(nums, 3), True)
        self.assertEqual(self.sln.containsNearbyDuplicate([1, 0, 1, 1], 1), True)
        self.assertEqual(self.sln.containsNearbyDuplicate([1, 2, 3, 1, 2, 3], 2), False)
