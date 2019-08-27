# -*- coding: utf-8 -*-
class Solution_1_10(object):
    def convert(self, s: str, numRows: int) -> str:
        """
        6
        :param s:
        :param numRows:
        :return:
        """
        if numRows == 1:
            return s

        item = []
        arr = []
        i = 0
        while s:
            item.append(s[0])
            i += 1
            s = s[1:]
            if i == 2 * numRows - 2:
                arr.append(item)
                item = []
                i = 0
        if item:
            arr.append(item)
        final_res = []
        for row in range(numRows):
            for idx in range(len(arr)):
                if len(arr[idx]) < row + 1:
                    continue
                final_res.append(arr[idx][row])
                if 0 < row < numRows - 1:
                    if len(arr[idx]) < 2 * numRows - 1 - row:
                        continue
                    final_res.append(arr[idx][2 * numRows - 2 - row])
        return ''.join(final_res)
