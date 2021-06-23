'''
    Never stops learning
    Rakesh Kumar
    24/06/2021
'''

import common

class BST(object):
    def search_iter(self, root, k):
        if root is not None:
            node = root
            while node:
                if k == node.val:
                    return True
                if k < node.val:
                    node = node.left
                else:
                    node = node.right
        return False

    def search_rec(self, root, k):
        if root is None:
            return False
        if k == root.val:
            return True
        if k < root.val:
            return self.search_rec(root.left, k)
        else:
            return self.search_rec(root.right, k)

    '''
        find the nearest or exact value to k in the BST
    '''
    def nearest(self, root, k):
        res = 0
        if root is not None:
            node = root
            diff = 10*100
            while node:
                if k == node.val:
                    return k
                if abs(k - node.val) < diff:
                    diff = abs(k - node.val)
                    res = node.val
                if k < node.val:
                    node = node.left
                else:
                    node = node.right
        return res
                    

    def min(self, root):
        node = root
        while node.left:
            node = node.left
        return node.val

    def max(self, root):
        node = root
        while node.right:
            node = node.right
        return node.val