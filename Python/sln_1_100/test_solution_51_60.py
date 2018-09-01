from unittest import TestCase
from sln_1_100.solution_51_60 import Solution_51_60


# -*- coding: UTF-8 -*-
class TestSolution_51_60(TestCase):
    def setUp(self):
        self.sln = Solution_51_60()

    def test_spiralOrder(self):
        m = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        res = [1, 2, 3, 6, 9, 8, 7, 4, 5]
        self.assertEqual(self.sln.spiralOrder(m), res)
        self.assertEqual(self.sln.spiralOrder([[1]]), [1])

    def test_lengthOfLastWord(self):
        length = self.sln.lengthOfLastWord('Hello world')
        self.assertEqual(length, 5)
        self.assertEqual(self.sln.lengthOfLastWord('  '), 0)
        self.assertEqual(self.sln.lengthOfLastWord('a  '), 1)
