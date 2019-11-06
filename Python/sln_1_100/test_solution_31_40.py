from unittest import TestCase

from sln_1_100.solution_31_40 import Solution_31_40


# -*- coding: UTF-8 -*-
class TestSolution_31_40(TestCase):
    def setUp(self):
        self.sln = Solution_31_40()

    def test_nextPermutation(self):
        nums1 = [1, 1, 5]
        self.sln.nextPermutation(nums1)
        assert nums1 == [1, 5, 1]
        nums2 = [3, 2, 1]
        self.sln.nextPermutation(nums2)
        assert nums2 == [1, 2, 3]
        nums3 = [1, 3, 2]
        self.sln.nextPermutation(nums3)
        assert nums3 == [2, 1, 3]
        num4 = [1, 5, 1]
        self.sln.nextPermutation(num4)
        assert num4 == [5, 1, 1]
        nums5 = [5, 4, 7, 5, 3, 2]
        self.sln.nextPermutation(nums5)
        assert nums5 == [5, 5, 2, 3, 4, 7]

    def test_searchInsert(self):
        ret1 = self.sln.searchInsert([1, 3, 5, 6], 5)
        self.assertEqual(ret1, 2)
        self.assertEqual(self.sln.searchInsert([], 0), 0)
        self.assertEqual(self.sln.searchInsert([1, 2, 3], 0), 0)
        self.assertEqual(self.sln.searchInsert([1, 2, 3], 10), 3)

    def test_countAndSay(self):
        self.assertEqual(self.sln.countAndSay(2), '11')
        self.assertEqual(self.sln.countAndSay(4), '1211')

    def test_combinationSum(self):
        ret = self.sln.combinationSum([2, 3, 6, 7], 7)
        print(ret)
