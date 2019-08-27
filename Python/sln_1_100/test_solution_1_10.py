# -*- coding: utf-8 -*-
from unittest import TestCase
from sln_1_100.solution_1_10 import Solution_1_10


class Test_Solution_1_10(TestCase):
    def setUp(self) -> None:
        self.sln = Solution_1_10()

    def test_convert(self):
        self.assertEqual(self.sln.convert("PAYPALISHIRING", 3), "PAHNAPLSIIGYIR")
        self.assertEqual(self.sln.convert("AB", 1), "AB")
