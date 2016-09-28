import unittest


class Select:
    def __init__(self, array):
        self.array = array

    def select_min(self, start=None, end=None, i=None):
        """
        Select the ith element from a given array[start: end].
        If `i` is not available return minimum.
        Time complexity: O(n)
        """
        i = 1 if i is None else i
        start = 0 if start is None else start
        end = len(self.array)-1 if end is None else end

        if start == end:
            return self.array[start]

        pivot = self.partition(start, end)
        k = pivot - start + 1

        if i == k:
            return self.array[pivot]
        elif i < k:
            return self.select_min(start, pivot-1, i)
        else:
            return self.select_min(pivot+1, end, i-pivot-1)


    def partition(self, l, r):
        array = self.array

        pivot_tuple = sorted([(array[l],l), (array[(l+r)/2],(l+r)/2), (array[r],r)])[1]
        pivot_index = pivot_tuple[1]
        array[l], array[pivot_index] = array[pivot_index], array[l]

        pivot = array[l]; i = l;

        for j in range(l, r+1):
            if array[j] < pivot:
                i += 1
                array[i], array[j] = array[j], array[i]

        array[i], array[l] = array[l], array[i]
        return i


class SelectTest(unittest.TestCase):
    def test_select_min(self):
        select_array = Select([1,2,3,4,5,6,8])
        self.assertEqual(select_array.select_min(), 1)
        self.assertEqual(select_array.select_min(i=3), 3)

if __name__ == "__main__":
    unittest.main()
