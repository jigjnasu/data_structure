'''
    Never stops learning
    Rakesh Kumar
    24/06/2021
'''

import list

'''
    list push_front, push_back and traversal test
    adding front and back functions as well
'''
def test_push():
    head1 = None
    l = list.List()
    for i in range(1, 21):
        head1 = l.push_front(head1, i)
    l.traverse(head1)

    head2 = None
    l = list.List()
    for i in range(1, 21):
        head2 = l.push_back(head2, i)
    l.traverse(head2)

    print('front item at the list == [{}] || [{}]'.format(l.front(head1), l.front(head2)))
    print('back  item at the list == [{}] || [{}]'.format(l.back(head1), l.back(head2)))

if __name__ == '__main__':
    test_push()