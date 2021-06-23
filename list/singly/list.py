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

    def push_back(self, head, val):
        if head is None:
            head = common.Node(val)
        else:
            node = head
            while node.next:
                node = node.next
            node.next = common.Node(val)
        return head

    def front(self, head):
        if head:
            return head.val
        else:
            return None
    
    def back(self, head):
        if head:
            node = head
            while node.next:
                node = node.next
            return node.val
        else:
            return None

    def search(self, head, k):
        if head:
            node = head
            while node:
                if k == node.val:
                    return True
                node = node.next
        return False

    '''
        let's start the head from 1 to n elements
        and return the kth element in the list
    '''
    def kth_element(self, head, k):
        if head:
            i = 1
            node = head
            while node:
                if i == k:
                    return node.val
                i += 1
                node = node.next
        return None

    def reverse(self, head):
        curr = head
        next = None
        prev = None
        while curr:
            next = curr.next
            curr.next = prev
            prev = curr
            curr = next
        head = prev
        return head

    def traverse(self, head):
        print('--------------------------------------------------')
        node = head
        while node:
            print(node.val, end=' ')
            node = node.next
        print('')
        print('--------------------------------------------------')