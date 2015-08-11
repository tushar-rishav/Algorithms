"""
    In-place version.
    Time Complexity: O(n^2) worst case
    Space Complexity: O(log n) this version

"""
from random import randrange

def partition(seq, left, right, pivot_index):
    pivot_value = seq[pivot_index]
    seq[pivot_index], seq[right] = seq[right], seq[pivot_index]
    store_index = left
    for i in range( left, right ):
        if seq[i] < pivot_value:
            seq[i], seq[store_index] = seq[store_index], seq[i]
            store_index += 1
    seq[store_index], seq[right] = seq[right], seq[store_index]
    return store_index

def sort(seq, left, right):
    """in-place version of quicksort"""
    if len(seq) <= 1:
        return seq
    elif left < right:
        #pivot = (left+right)/2
        pivot = randrange(left, right)
        pivot_new_index = partition(seq, left, right, pivot)
        sort(seq, left, pivot_new_index - 1)
        sort(seq, pivot_new_index + 1, right)
        return seq
