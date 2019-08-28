# -*- coding: utf-8 -*-
from unittest import TestCase
from sln_1_100.solution_71_80 import Solution_71_80


class TestSolution_71_80(TestCase):
    def setUp(self):
        self.sln = Solution_71_80()

    def test_simplifyPath(self):
        ret = self.sln.simplifyPath('/a/./b/../../c/')
        print(ret)
        ret2 = self.sln.simplifyPath('/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///')
        print(ret2)
        self.assertEqual(self.sln.simplifyPath('///'), '/')
        self.assertEqual(self.sln.simplifyPath('/...'), '/...')

    def test_search_martrix(self):
        matrix = [
            [1, 3, 5, 7],
            [10, 11, 16, 20],
            [23, 30, 34, 50]
        ]
        self.assertEqual(self.sln.searchMatrix(matrix, 3), True)
        self.assertEqual(self.sln.searchMatrix(matrix, 7), True)
        self.assertEqual(self.sln.searchMatrix(matrix, 11), True)
        self.assertEqual(self.sln.searchMatrix(matrix, 50), True)
        self.assertEqual(self.sln.searchMatrix(matrix, 8), False)
        self.assertEqual(self.sln.searchMatrix(matrix, 100), False)
        self.assertEqual(self.sln.searchMatrix(matrix, 23), True)
        self.assertEqual(self.sln.searchMatrix(matrix, 0), False)
        self.assertEqual(self.sln.searchMatrix(matrix, 1), True)
        self.assertEqual(self.sln.searchMatrix([], 1), False)
        self.assertEqual(self.sln.searchMatrix([[]], 1), False)

    def test_combine(self):
        ret = self.sln.combine(4, 2)
        self.assertEqual(ret, [[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]])

    def test_sortColors(self):
        arr = [2, 0, 2, 1, 1, 0]
        self.sln.sortColors(arr)
        assert arr == [0, 0, 1, 1, 2, 2]
        arr1 = [2, 0, 1]
        self.sln.sortColors(arr1)
        assert arr1 == [0, 1, 2]
