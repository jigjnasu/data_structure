'''
    Never stops learning
    Rakesh Kumar
    23/06/2021
'''

import common
import bst

def get_tree_iter():
    arr = [100, 50, 150, 25, 75, 125, 175, 30, 45, 55, 65, 165, 185, 200, 15, 20, 10, 5, 1, 7, 9, 23, 180, 300]
    b = bst.BST()
    root = None
    for e in arr:
        root = b.insert_iter(root, e)
    return root

def get_tree_rec():
    arr = [100, 50, 150, 25, 75, 125, 175, 30, 45, 55, 65, 165, 185, 200, 15, 20, 10, 5, 1, 7, 9, 23, 180, 300]
    b = bst.BST()
    root = None
    for e in arr:
        root = b.insert_rec(root, e)
    return root


def test_insert():
    b = bst.BST()
    root1 = get_tree_iter()
    root2 = get_tree_rec()
    b.bfs(root1)
    b.bfs(root2)

def test_traversals():
    b = bst.BST()
    root = get_tree_iter()
    b.bfs(root)
    print('--------------------------------- pre order ------------------------------')
    b.preorder(root)
    print('')
    print('--------------------------------- in order -------------------------------')
    b.inorder(root)
    print('')
    print('--------------------------------- post order ------------------------------')
    b.postorder(root)
    print('')

if __name__ == '__main__':
    #test_insert()
    test_traversals()
