# -*- coding: UTF-8 -*-

class Solution_41_50:
    def groupAnagrams(self, strs):
        """
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
