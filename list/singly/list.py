'''
    Never stops learning
    Rakesh Kumar
    24/06/2021
'''

import common

class List(object):
    def push_front(self, head, val):
        if head is None:
            head = common.Node(val)
        else:
            node = common.Node(val)
            node.next = head
            head = node
        return head

    def traverse(self, head):
        print('--------------------------------------------------')
        node = head
        while node:
            print(node.val, end=' ')
            node = node.next
        print('')
        print('--------------------------------------------------')