# -*- coding: utf-8 -*-
from sln_1_100.solution_61_70 import Solution_61_70
from unittest import TestCase
class TestSolution_61_70(TestCase):
    def setUp(self):
        self.sln = Solution_61_70()

    def test_addBinary(self):
        ret = self.sln.addBinary('11','1')
        print(ret)