from unittest import TestCase

from solution_31_40 import Solution_31_40


# -*- coding: UTF-8 -*-
class TestSolution_31_40(TestCase):
  def setUp(self):
    self.sln = Solution_31_40()

  def test_countAndSay(self):
    self.assertEqual(self.sln.countAndSay(2), '11')
    self.assertEqual(self.sln.countAndSay(4), '1211')
