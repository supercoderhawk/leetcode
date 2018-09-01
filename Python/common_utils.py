# -*- coding: utf-8 -*
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


def print_linked_list(head):
    node = head
    s = ''
    while node:
        s += str(node.val)
        if node.next:
            s += '->'
        node = node.next
    print(s)

class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e