'''
    Never stops learning
    Rakesh Kumar
    23/06/2021
'''

import common
import bst
import bst_search

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

'''
    test case of insert iterative and recursive approach
'''
def test_insert():
    b = bst.BST()
    root1 = get_tree_iter()
    root2 = get_tree_rec()
    b.bfs(root1)
    b.bfs(root2)

'''
    test case for traversal testing pre, in, post and bfs
'''
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
    print('----------------------------- pre order data ------------------------------')
    print(b.preorder_data(root))
    print('----------------------------- in order data -------------------------------')
    print(b.inorder_data(root))
    print('----------------------------- post order data -----------------------------')
    print(b.postorder_data(root))

'''
    testing of height of the tree
'''
def test_height():
    b = bst.BST()
    root = get_tree_iter()
    b.bfs(root)
    print('height of the tree == [{}]'.format(b.height(root)))

'''
    testing for searching in bst
'''
def test_search():
    b = bst.BST()
    root = get_tree_iter()
    b.bfs(root)
    bs = bst_search.BST()
    k = 199
    print('[{}] found in tree == [{}] || [{}]'.format(k, bs.search_iter(root, k), bs.search_rec(root, k)))
    k = 7
    print('[{}] found in tree == [{}] || [{}]'.format(k, bs.search_iter(root, k), bs.search_rec(root, k)))
    k = 300
    print('[{}] found in tree == [{}] || [{}]'.format(k, bs.search_iter(root, k), bs.search_rec(root, k)))
    k = -125
    print('[{}] found in tree == [{}] || [{}]'.format(k, bs.search_iter(root, k), bs.search_rec(root, k)))
    k = 187
    print('[{}] found in tree == [{}] || [{}]'.format(k, bs.search_iter(root, k), bs.search_rec(root, k)))

    print('mimimum value in tree == [{}]'.format(bs.min(root)))
    print('maximum value in tree == [{}]'.format(bs.max(root)))

if __name__ == '__main__':
    #test_insert()
    #test_traversals()
    #test_height()
    test_search()
