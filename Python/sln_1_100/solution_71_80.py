# -*- coding: utf-8 -*-
from typing import List
import copy
import math


class Solution_71_80(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        if not path or path == '/':
            return path

        r_offset = 0
        while len(path) - 1 >= r_offset and path[len(path) - 1 - r_offset] == '/':
            r_offset += 1

        if r_offset:
            path = path[:-r_offset]

        if not path:
            return '/'

        path_segments = path[1:].split('/')
        final_path_segments = []

        for segment in path_segments:
            if segment == '..':
                if final_path_segments:
                    final_path_segments.pop()
            elif segment in {'.', ''}:
                continue
            else:
                final_path_segments.append(segment)

        return '/' + '/'.join(final_path_segments)

    def combine(self, n: int, k: int) -> List[List[int]]:
        """
        77
        :param n:
        :param k:
        :return:
        """

        results = []

        def backtrace(res=[]):
            if len(res) == k:
                results.append(res)
            else:
                if not res:
                    m = 1
                else:
                    m = res[-1] + 1
                for i in range(m, n + 1):
                    backtrace(res + [i])

        backtrace()
        return results
