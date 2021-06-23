'''
    Never stops learning
    Rakesh Kumar
    24/06/2021
'''

import list

'''
    list push_front, push_back and traversal test
'''
def test_push():
    head = None
    l = list.List()
    for i in range(1, 21):
        head = l.push_front(head, i)
    l.traverse(head)


if __name__ == '__main__':
    test_push()