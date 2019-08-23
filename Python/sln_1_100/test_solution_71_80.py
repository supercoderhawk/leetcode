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

    def test_combine(self):
        ret = self.sln.combine(4, 2)
        self.assertEqual(ret, [[1, 2], [1, 3], [1, 4], [2, 3], [2, 4], [3, 4]])
