# -*- coding: utf-8 -*-
from unittest import TestCase
from sln_101_200.solution_131_140 import Solution_131_140


class TestSolution_131_140(TestCase):
    def setUp(self):
        self.sln = Solution_131_140()

    def test_partition(self):
        self.assertEqual([['a', 'a', 'b'], ['aa', 'b']], self.sln.partition('aab'))
        self.assertEqual([["a", "b", "b", "a", "b"], ["a", "b", "bab"], ["a", "bb", "a", "b"], ["abba", "b"]],
                         self.sln.partition('abbab'))

    def test_singleNumber(self):
        ret = self.sln.singleNumber([2, 2, 1])
        self.assertEqual(ret, 1)
