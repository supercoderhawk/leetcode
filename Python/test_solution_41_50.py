from unittest import TestCase
from solution_41_50 import Solution_41_50

# -*- coding: UTF-8 -*-
class TestSolution_41_50(TestCase):
  def setUp(self):
    self.sln = Solution_41_50()

  def test_groupAnagrams(self):
    a = ["eat", "tea", "tan", "ate", "nat", "bat"]
    b = [['eat', 'tea', 'ate'], ['tan', 'nat'], ['bat']]
    self.assertEqual(self.sln.groupAnagrams(a),b)
    self.assertEqual(self.sln.groupAnagrams(['']), [['']])
