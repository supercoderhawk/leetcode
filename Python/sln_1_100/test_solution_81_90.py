# -*- coding: utf-8 -*-
from unittest import TestCase
from sln_1_100.solution_81_90 import *
from common_utils import *

class Test_Solution_81_90(TestCase):
    def setUp(self) -> None:
        self.sln = Solution_81_90()



    def test_partition(self):
        head = build_linked_list([1,4,3,2,5,2])
        ret = self.sln.partition(head,3)
        print_linked_list(ret)