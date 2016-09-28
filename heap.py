import unittest


class Heap:
    def __init__(self, array):
        self._heap = array # 0 indexed array
        self._array_size = len(array)
        self.deleted_keys = set() # For implementing arbitrary key delete

    @property
    def heap_size(self): return self._array_size

    @property
    def heap(self): return self._heap

    @property
    def get_min(self):
        while self._heap[0] in self.deleted_keys:
            self.heap_deleted_key(0)

        return self._heap[0]

    @staticmethod
    def left(i): return (i<<1)+1

    @staticmethod
    def right(i): return (i<<1|1)+1

    @staticmethod
    def parent(i): return (i-1)>>1

    def max_heapify(self, index):
        """
        Assumption: Binary tree rooted at left and right are max heap.
        """
        l = Heap.left(index)
        r = Heap.right(index)
        largest = index

        if l < self.heap_size and self.heap[l] > self.heap[largest]:
            largest = l
        if r < self.heap_size and self.heap[r] > self.heap[largest]:
            largest = r
        if largest is not index:
            self.heap[largest], self.heap[index] = \
            self.heap[index], self.heap[largest]
            return self.max_heapify(largest)

    def min_heapify(self, index):
        """
        Assumption: Binary tree rooted at left and right are min heap.
        """
        l = Heap.left(index)
        r = Heap.right(index)
        smallest = index

        if l < self.heap_size and self.heap[l] < self.heap[smallest]:
            smallest = l
        if r < self.heap_size and self.heap[r] < self.heap[smallest]:
            smallest = r
        if smallest is not index:
            self.heap[smallest], self.heap[index] = \
            self.heap[index], self.heap[smallest]
            return self.min_heapify(smallest)

    def build_max_heap(self):
        """
        Build max heap bottom up.
        """
        for index in range((self.heap_size-1)/2, -1, -1):
            self.max_heapify(index)

    def build_min_heap(self):
        """
        Build min heap bottom up.
        """
        for index in range((self.heap_size-1)/2, -1, -1):
            self.min_heapify(index)

    def heap_extract_max(self):
        """
        Extract maximum element from a heap and update the heap.
        """
        if self.heap_size < 1:
            return "Heap UnderFlow"
        h_max = self.heap[0]
        self.heap[0] = self.heap[self.heap_size-1]
        del self.heap[self.heap_size-1]
        self.heap_size -= 1
        self.max_heapify(0)
        return h_max

    def heap_extract_min(self):
        """
        Extract minimum element from a heap and update the heap.
        """
        if self.heap_size < 1:
            return "Heap UnderFlow"
        h_min = self.heap[0]
        self.heap[0] = self.heap[self.heap_size-1]
        del self.heap[self.heap_size-1]
        self.heap_size -= 1
        self.min_heapify(0)
        return h_min

    def heap_increase_key(self, index, key):
        """
        Increase the key value of node at index `index`.
        The key value must be at least current value.
        It maintains the max heap invariants.
        """
        if key < self.heap[index]:
            raise Exception("new key is smaller than current key")

        self.heap[index] = key
        while index > 0 and self.heap[self.parent(index)] < self.heap[index]:
            self.heap[self.parent(index)], self.heap[index] = \
            self.heap[index], self.heap[self.parent(index)]
            index = self.parent(index)

    def heap_decrease_key(self, index, key):
        """
        Decrease the key value of node at index `index`.
        The key value must be at max the current value.
        It maintains the min heap invariants.
        """
        if key > self.heap[index]:
            raise Exception("new key is greater than current key")

        self.heap[index] = key
        while index > 0 and self.heap[self.parent(index)] > self.heap[index]:
            self.heap[self.parent(index)], self.heap[index] = \
            self.heap[index], self.heap[self.parent(index)]
            index = self.parent(index)

    def heap_insert_key(self, key, minheap=False):
        """
        Insert a given `key` in the current heap.
        """
        self.heap_size += 1
        if not minheap:
            self.heap.append(float('-inf'))
            self.heap_increase_key(self.heap_size-1, key)
        else:
            self.heap.append(float('inf'))
            self.heap_decrease_key(self.heap_size-1, key)

    def heap_deleted_key(self, index):
        """
        Delete a node at given `index`.
        Time: O(logN)
        """
        self.heap[index], self.heap[self.heap_size-1] = \
            self.heap[self.heap_size-1], self.heap[index]
        del self.heap[self.heap_size-1]
        self.heap_size -= 1
        self.min_heapify(index)

    def heap_deleted_arbitrary_key(self, key):
        """
        Delete an arbitrary key from heap.
        Time: Time: O(1)
        The idea is to avoid search for the key in heap. No need to physically
        remove the element from the heap until it became the smallest. Just
        remember the deleted keys in a hash map and delete them when they become
        the root of heap.
        This can lead to O(1) runtime for the arbitrary delete operation
        instead of O(N).
        """
        self.deleted_keys.add(key)
        if self.heap[0] in self.deleted_keys:
            self.deleted_keys.remove(key)
            self.heap_deleted_key(0)


class HeapTest(unittest.TestCase):
    def setUp(self):
        self.h = Heap([27,17,3,16,13,10,1,5,7,12,4,8,9,0])

    def test_heap_size(self):
        self.assertEqual(self.h.heap_size, 14)

    def test_max_heapify(self):
        self.h.max_heapify(2)
        self.assertEqual(self.h.heap, [27,17,10,16,13,9,1,5,7,12,4,8,3,0])

    def test_min_heapify(self):
        self.h = Heap([4,0,3,1,2,6,7])
        self.h.min_heapify(0)
        self.assertEqual(self.h.heap, [0,1,3,4,2,6,7])

    def test_build_max_heap(self):
        self.h.build_max_heap()
        self.assertEqual(self.h.heap, [27,17,10,16,13,9,1,5,7,12,4,8,3,0])

    def test_build_min_heap(self):
        self.h.build_min_heap()
        self.assertEqual(self.h.heap, [0,4,1,5,12,8,3,16,7,17,13,10,9,27])

    def test_heap_extract_max(self):
        self.h.build_max_heap()
        self.assertEqual(self.h.heap_extract_max(), 27)
        self.assertEqual(self.h.heap, [17,16,10,7,13,9,1,5,0,12,4,8,3])

    def test_heap_increase_key(self):
        self.h.build_max_heap()
        self.h.heap_increase_key(self.h.heap_size-1, 50)
        self.assertEqual(self.h.heap, [50,17,27,16,13,9,10,5,7,12,4,8,3,1])

    def test_heap_decrease_key(self):
        self.h.build_min_heap()
        self.assertEqual(self.h.heap, [0,4,1,5,12,8,3,16,7,17,13,10,9,27])
        self.h.heap_decrease_key(self.h.heap_size-1, 2)
        self.assertEqual(self.h.heap, [0,4,1,5,12,8,2,16,7,17,13,10,9,3])

    def test_heap_insert_key(self):
        self.h.build_max_heap()
        self.h.heap_insert_key(6)
        self.assertEqual(self.h.heap, [27,17,10,16,13,9,6,5,7,12,4,8,3,0,1])


if __name__ == '__main__':
    unittest.main()
