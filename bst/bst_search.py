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
                if k == root.val:
                    return True
                if k < root.val:
                    node = node.left
                else:
                    node = node.right
        return False