# -*- coding: UTF-8 -*-

class Solution_31_40:
  def countAndSay(self, n):
    """
    :type n: int
    :rtype: str
    """
    curr = '1'
    for i in range(1, n):
      prev = curr
      curr = ''
      count = 1
      say = prev[0]
      for ch in prev[1:]:
        if say == ch:
          count += 1
        else:
          curr += str(count) + say
          say = ch
          count = 1
      curr += str(count) + say
    return curr
