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
    def build_from_sorted_array(self, arr):
        return self._build_from_sorted_array(arr, 0, len(arr) - 1)

    def _build_from_sorted_array(self, arr, low, high):
        if low > high:
            return None
        mid = (low + high) >> 1
        root = common.Node(arr[mid])
        root.left = self._build_from_sorted_array(arr, low, mid - 1)
        root.right = self._build_from_sorted_array(arr, mid + 1, high)
        return root
