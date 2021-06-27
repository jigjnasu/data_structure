'''
    Never stops learning
    Rakesh Kumar
    25/06/2021
'''

'''
    In this file we will only write functions
    which will construct the BSTs from different sources
    like from sorted list, array, pre order, post order arrays
    etc
'''

import common

class BST(object):
    def __init__(self) -> None:
        self._i = 0

    def reset(self):
        self._i = 0

    def build_from_sorted_array(self, arr):
        return self._build_from_sorted_array(arr, 0, len(arr) - 1)

    def build_from_pre_order_array(self, arr, bound = 100^10000):
        if self._i == len(arr) or arr[self._i] > bound:
            return None
        root = common.Node(arr[self._i])
        self._i += 1
        root.left = self.build_from_pre_order_array(arr, root.val)
        root.right = self.build_from_pre_order_array(arr, bound)
        return root

    def build_from_post_order_array(self, arr):
        pass

    def _build_from_sorted_array(self, arr, low, high):
        if low > high:
            return None
        mid = (low + high) >> 1
        root = common.Node(arr[mid])
        root.left = self._build_from_sorted_array(arr, low, mid - 1)
        root.right = self._build_from_sorted_array(arr, mid + 1, high)
        return root
