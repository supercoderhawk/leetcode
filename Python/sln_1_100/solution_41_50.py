# -*- coding: UTF-8 -*-

class Solution_41_50:
    def multiply(self, num1: str, num2: str) -> str:
        """
        43
        Given two non-negative integers num1 and num2 represented as strings,
        return the product of num1 and num2, also represented as a string.
        :param num1:
        :param num2:
        :return:
        """
        mul_ret = 0
        for idx1, digit1 in enumerate(num1[::-1]):
            val1 = (ord(digit1) - ord('0')) * 10 ** idx1
            for idx2, digit2 in enumerate(num2[::-1]):
                val2 = (ord(digit2) - ord('0')) * 10 ** idx2
                mul_ret += val1 * val2
        return str(mul_ret)

    def permute(self, nums):
        """
        problem 46
        Given a collection of distinct numbers, return all possible permutations.

        For example,
        [1,2,3] have the following permutations:
        [
          [1,2,3],
          [1,3,2],
          [2,1,3],
          [2,3,1],
          [3,1,2],
          [3,2,1]
        ]

        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = [[nums[0]]]
        for n in nums[1:]:
            old_res = res
            res = []

            for l in old_res:
                res.extend(list(map(lambda i: l[:i] + [n] + l[i:], range(len(l) + 1))))
        return res

    def groupAnagrams(self, strs):
        """
        problem 49

        Given an array of strings, group anagrams together.

        For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
        Return:

        [
          ["ate", "eat","tea"],
          ["nat","tan"],
          ["bat"]
        ]
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        word_maps = {}
        if len(strs) <= 1:
            return [strs]

        word_maps[str(sorted(strs[0]))] = [strs[0]]
        for s in strs[1:]:
            sign = str(sorted(s))
            if sign not in word_maps:
                word_maps[sign] = [s]
            else:
                word_maps[sign].append(s)

        return word_maps.values()
