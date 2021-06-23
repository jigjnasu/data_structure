'''
    Never stops learning
    Rakesh Kumar
    24/06/2021
'''

import list

'''
    list push_front, push_back and traversal test
    adding front and back functions as well
    search an item
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

    k = 20
    print('[{}] is in the list == [{}]'.format(k, l.search(head2, k)))
    k = 29
    print('[{}] is in the list == [{}]'.format(k, l.search(head2, k)))

'''
    let's test the revering of the linked list
    find kth element in the list
'''
def test_reverse():
    head = None
    l = list.List()
    for i in range(1, 51):
        head = l.push_front(head, i)
    l.traverse(head)
    head = l.reverse(head)
    l.traverse(head)

    k = 51
    print('[{}]th element in the list == [{}]'.format(k, l.kth_element(head, k)))
    k = 13
    print('[{}]th element in the list == [{}]'.format(k, l.kth_element(head, k)))

if __name__ == '__main__':
    #test_push()
    test_reverse()
