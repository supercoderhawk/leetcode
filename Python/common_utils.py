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
    return s


def build_linked_list(arr):
    head = node = None
    for val in arr:
        if head is None:
            head = node = ListNode(val)
        else:
            node.next = ListNode(val)
            node = node.next
    return head


class Interval:
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
