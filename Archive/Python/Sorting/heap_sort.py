"""
    Time Complexity: O(n log n)
    Space Complexity: O(1) Auxiliary
"""
def max_heapify(seq, i, n):
    l = 2 * i + 1
    r = 2 * i + 2

    if l <= n and seq[l] > seq[i]:
        largest = l
    else:
        largest = i
    if r <= n and seq[r] > seq[largest]:
        largest = r

    if largest != i:
        seq[i], seq[largest] = seq[largest], seq[i]
        max_heapify(seq, largest, n)


def build_heap(seq):
    n = len(seq) - 1
    for i in range(n/2, -1, -1):
        max_heapify(seq, i, n)


def sort(seq):
    build_heap(seq)
    heap_size = len(seq) - 1
    for x in range(heap_size, 0, -1):
        seq[0], seq[x] = seq[x], seq[0]
        heap_size = heap_size - 1
        max_heapify(seq, 0, heap_size)

    return seq
