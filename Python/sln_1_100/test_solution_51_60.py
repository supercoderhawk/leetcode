from unittest import TestCase
from sln_1_100.solution_51_60 import Solution_51_60
from common_utils import Interval


# -*- coding: UTF-8 -*-
class TestSolution_51_60(TestCase):
    def setUp(self):
        self.sln = Solution_51_60()

    def test_spiralOrder(self):
        m = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        res = [1, 2, 3, 6, 9, 8, 7, 4, 5]
        self.assertEqual(self.sln.spiralOrder(m), res)
        self.assertEqual(self.sln.spiralOrder([[1]]), [1])

    def test_merge(self):
        raw_span1 = [[1, 3], [2, 6], [8, 10], [15, 18]]
        span1 = [Interval(start, end) for start, end in raw_span1]

    def test_lengthOfLastWord(self):
        length = self.sln.lengthOfLastWord('Hello world')
        self.assertEqual(length, 5)
        self.assertEqual(self.sln.lengthOfLastWord('  '), 0)
        self.assertEqual(self.sln.lengthOfLastWord('a  '), 1)

    def test_generateMatrix(self):
        matrix = self.sln.generateMatrix(3)
        self.assertEqual(matrix, [[1, 2, 3], [8, 9, 4], [7, 6, 5]])

    def test_getPermutation(self):
        self.assertEqual(self.sln.getPermutation(3, 3),'213')
        self.assertEqual(self.sln.getPermutation(3, 5),'312')
        self.assertEqual(self.sln.getPermutation(1, 1),'1')
        self.assertEqual(self.sln.getPermutation(2, 2),'21')
        self.assertEqual(self.sln.getPermutation(4, 2),'1243')
