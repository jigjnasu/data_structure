'''
    Never stops learning
    Rakesh Kumar
    23/06/2021
'''

import common
import bst

def get_tree():
    arr = [100, 50, 150, 25, 75, 125, 175, 30, 45, 55, 65, 165, 185, 200, 15, 20, 10, 5, 1, 7, 9, 23, 180, 300]
    b = bst.BST()
    root = None
    for e in arr:
        root = b.insert_iter(root, e)
    return root

def test_insert():
    b = bst.BST()
    root1 = get_tree()
    b.bfs(root1)

if __name__ == '__main__':
    test_insert()
