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

    def sort(self, head):
        if head is None or head.next is None:
            return head
        mid = self._get_middle(head)
        mid_next = mid.next
        mid.next = None
        left = self.sort(head)
        right = self.sort(mid_next)
        new_head = self._merge(left, right)
        return new_head

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

    def _merge(self, left, right):
        if left is None:
            return right
        elif right is None:
            return left
        else:
            new_head = None
            if left.val < right.val:
                new_head = left
                new_head.next = self._merge(left.next, right)
            else:
                new_head = right
                new_head.next = self._merge(left, right.next)
            return new_head

    def _get_middle(self, head):
        slow = head
        fast = head
        while fast and fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        return slow