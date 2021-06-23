'''
    Never stops learning
    Rakesh Kumar
    23/06/2021
'''

import common

class BST(object):
    def insert_iter(self, root, val):
        if root == None:
            root = common.Node(val)
        else:
            node = root
            while node:
                if val < node.val:
                    if node.left == None:
                        node.left = common.Node(val)
                        break
                    else:
                        node = node.left
                else:
                    if node.right == None:
                        node.right = common.Node(val)
                        break
                    else:
                        node = node.right
        return root

    def insert_rec(self, root, val):
        if root == None:
            root = common.Node(val)
        else:
            if val < root.val:
                root.left = self.insert_rec(root.left, val)
            else:
                root.right = self.insert_rec(root.right, val)
        return root

    def bfs(self, root):
        print('--------------------------------------------------------')
        if root is not None:
            q = []
            q.append(root)
            while len(q) > 0:
                i = len(q)
                while i > 0:
                    root = q.pop(0)
                    print(root.val, end = ' ')
                    if root.left is not None:
                        q.append(root.left)
                    if root.right is not None:
                        q.append(root.right)
                    i -= 1
                print('')
        print('--------------------------------------------------------')
