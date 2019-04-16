# -*- coding: utf-8 -*-

class Solution_61_70(object):
    def addBinary(self, a, b):
        """
        67
        :type a: str
        :type b: str
        :rtype: str
        """
        if len(a) > len(b):
            max_len = len(a)
            b = '0' * (len(a) - len(b)) + b
        else:
            max_len = len(b)
            a = '0' * (len(b) - len(a)) + a

        result = []
        carry = 0
        for ch_a, ch_b in zip(a[::-1], b[::-1]):
            bit = int(ch_a) + int(ch_b) + carry
            if bit > 1:
                result.append(str(bit - 2))
                carry = 1
            else:
                result.append(str(bit))
                carry = 0

        if carry == 1:
            result.append('1')

        return ''.join(result[::-1])
