from heap import Heap
import unittest


class MergeSort:
    """
    Time Complexity: O(nlog(n))
    """
    def __init__(self, array):
        self.array = array
        self._inv_count = 0

    @property
    def inversion_count(self):
        """
        Return the inversion count for the original unsorted array.
        """
        return self._inv_count

    def merge(self, ar_left, ar_right):
        result = []
        l0 = len(ar_left); r0 = len(ar_right)
        l = r = 0
        while l < l0 and r < r0:
            if ar_left[l] < ar_right[r]:
                result.append(ar_left[l])
                l += 1
            else:
                result.append(ar_right[r])
                self._inv_count += (l0-l)
                r += 1

        if l != l0:
            for elem in ar_left[l:]:
                result.append(elem)
        else:
            for elem in ar_right[r:]:
                result.append(elem)

        return result

    def msort(self, array=None):
        if array is None:
            array = self.array

        ar_len = len(array)
        if ar_len < 2:
            return array

        ar_left_sorted = self.msort(array[: ar_len/2])
        ar_right_sorted = self.msort(array[ar_len/2 :])
        return self.merge(ar_left_sorted, ar_right_sorted)


class QuickSort:
    """
    In place sort.
    Avg time complexity: O(nlog(n))
    """
    def __init__(self, array):
        self.array = array
        self.comparison = 0

    def partition(self, l, r):
        """
        Median of first, middle and last element is taken as pivot element.
        """
        array = self.array
        pivot_tuple = sorted([(array[l],l),
                              (array[(l+r)/2],(l+r)/2),
                              (array[r],r)])[1]
        pivot_index = pivot_tuple[1]
        array[l], array[pivot_index] = array[pivot_index], array[l]
        pivot = array[l]
        i = l
        for j in range(l, r+1):
            if array[j] < pivot:
                i += 1
                array[i], array[j] = array[j], array[i]
        array[i], array[l] = array[l], array[i]

        return i

    def tail_recursion_qsort(self, l, r):
        """
        Optimised version of Quick sort using Tail recursion.
        """
        while l < r:
            pivot_index = self.partition(l, r)
            self.comparison += (r - l)
            self.qsort(l, pivot_index-1)
            l = pivot_index + 1

    def qsort(self, l, r):
        if l < r:
            pivot_index = self.partition(l, r)
            self.comparison += (r - l)
            self.qsort(l, pivot_index-1)
            self.qsort(pivot_index + 1, r)


class HeapSort(Heap):
    def __init__(self, array):
        Heap.__init__(self, array)

    def heapsort(self, reverse = False):
        """
        Inplace sort.
        Time Complexity: O(N*log(N))
        :param reverse:
            A boolean `True` value if the array is to be sorted in
            descending order otherwise default is False.
        """
        if not reverse:
            self.build_max_heap()
        else:
            self.build_min_heap()
        for index in range(self.heap_size-1, 0, -1):
            self.heap[0], self.heap[index] = self.heap[index], self.heap[0]
            self.heap_size -= 1
            if not reverse:
                self.max_heapify(0)
            else:
                self.min_heapify(0)
        return self.heap


class CountSort:
    """
    Stable linear sort.
    Time Complexity: O(n)
    """
    def __init__(self, array):
        self.array = array

    def csort(self):
        l_freq = max(self.array)+1
        freq = [0] * l_freq
        for elem in self.array:
            freq[elem] += 1
        for i in range(1, l_freq):
            freq[i] = freq[i] + freq[i-1]

        sorted_array = [0] * (len(self.array)+1)
        for elem in self.array[-1::-1]:
            sorted_array[freq[elem]] = elem
            freq[elem] -= 1

        del sorted_array[0]
        return sorted_array


class SortTest(unittest.TestCase):
    def test_merge_sort(self):
        msort_array = MergeSort([5,2,3,1,0])
        self.assertEqual(msort_array.msort(), [0,1,2,3,5])
        self.assertEqual(msort_array.inversion_count, 9)
        msort_array = MergeSort([5,2,3,1])
        self.assertEqual(msort_array.msort(), [1,2,3,5])
        self.assertEqual(msort_array.inversion_count, 5)

    def test_quick_sort(self):
        qsort_array = QuickSort([0,5,2,8,9,1,7,4])
        qsort_array.qsort(0, len(qsort_array.array)-1)
        self.assertEqual(qsort_array.array, [0,1,2,4,5,7,8,9])

    def test_heap_sort(self):
        h = HeapSort([4,5,6,3,2,1])
        self.assertEqual(h.heapsort(), [1,2,3,4,5,6])
        h = HeapSort([4,5,6,3,2,1])
        self.assertEqual(h.heapsort(reverse=True), [6,5,4,3,2,1])

    def test_count_sort(self):
        csort_array = CountSort([0,5,2,8,9,1,7,4])
        self.assertEqual(csort_array.csort(), [0,1,2,4,5,7,8,9])


if __name__ == "__main__":
    unittest.main()
