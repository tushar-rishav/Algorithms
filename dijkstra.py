from heap import Heap
import unittest


class HeapNode:
    def __init__(self, node_id, key, location):
        self.key = key
        self.location = location
        self.parent = []
        self.id = node_id

    def __lt__(self, y):
        return self.key < y.key

    def __eq__(self, y):
        return self.key == y.key

    def __le__(self, y):
        return self.__lt__(y) or self.__eq__(y)

    def __gt__(self, y):
        return not self.__lt__(y)

    def __ne__(self, y):
        return not self.__eq__(y)

    def __ge__(self, y):
        return self.__gt__(y) or self.__eq__(y)

    def __repr__(self):
        return "({0}, key:{1}, loc: {2}, p: {3})".format(self.id,
                                                         self.key,
                                                         self.location,
                                                         self.parent)


class MinHeap(Heap):
    def __init__(self, *args, **kwargs):
        Heap.__init__(self, *args, **kwargs)

    def min_heapify(self, index):
        l = Heap.left(index)
        r = Heap.right(index)
        smallest = index
        if l < self.heap_size and self.heap[l] < self.heap[smallest]:
            smallest = l
        if r < self.heap_size and self.heap[r] < self.heap[smallest]:
            smallest = r
        if smallest is not index:
            self.heap[smallest].location, self.heap[index].location = \
            self.heap[index].location, self.heap[smallest].location
            self.heap[smallest], self.heap[index] = \
            self.heap[index], self.heap[smallest]
            return self.min_heapify(smallest)

    def heap_extract_min(self):
        """
        Extract minimum element from a heap and update the heap.
        """
        if self.heap_size < 1:
            return "Heap UnderFlow"
        h_min = self.heap[0]
        self.heap[0] = self.heap[self.heap_size-1]
        self.heap[0].location = 0
        del self.heap[self.heap_size-1]
        self.heap_size -= 1
        self.min_heapify(0)
        return h_min

    def heap_decrease_key(self, index, key):
        """
        Decrease the key value of node at index `index`.
        The key value must be at max the current value.
        It maintains the min heap invariants.
        """
        if key > self.heap[index].key:
            raise Exception("new key is greater than current key")

        self.heap[index].key = key
        while index > 0 and self.heap[self.parent(index)] > self.heap[index]:
            self.heap[self.parent(index)], self.heap[index] = \
            self.heap[index], self.heap[self.parent(index)]
            self.heap[self.parent(index)].location, self.heap[index].location = \
            self.heap[index].location, self.heap[self.parent(index)].location
            index = self.parent(index)


class Graph:
    def __init__(self, adj_list):
        """
        The `adj_list` is a map with node as key and value as list of tuples as
        node ids and edge weight. For example:
        {
            node1: [(node2, w12), (node3, w13)],
            node2: [(node3, w23)],
            node3: [(node1, w31), (node2, w32)]
        }
        """
        self.adj_list = adj_list

    def _init_vetices_and_build_min_heap(self):
        self.heap = [HeapNode(node, float('inf'), node)
                     if node != self.source else HeapNode(node, 0, node)
                     for node in self.adj_list.keys()]

    def _relax(self, u, v, d):
        if u.key + d < v.key:
            self.node_map[v.id].key = u.key + d
            self.node_map[v.id].parent = u.id
            self.h.heap_decrease_key(v.location, v.key)

    def dijkstra(self, source):
        """
        Compute minimum distance for all vertices from a given source.
        """
        self.source = source
        self._init_vetices_and_build_min_heap()
        self.h = MinHeap(self.heap)
        self.node_map = {node.id: node for node in self.h.heap}
        while self.h.heap_size:
            u = self.h.heap_extract_min()
            for v in self.adj_list[u.id]:
                self._relax(u, self.node_map[v[0]], v[1])

        # print self.node_map


class HeapNodeTest(unittest.TestCase):
    def test_comparison(self):
        n1 = HeapNode(1,4,1)
        n2 = HeapNode(2,5,2)
        n3 = HeapNode(3,4,3)
        n4 = HeapNode(4,4,1)
        self.assertTrue(n1 < n2)
        self.assertTrue(n3 < n2)
        self.assertTrue(n1 == n4)
        self.assertTrue(n1 <= n2)
        self.assertFalse(n1 < n3)
        self.assertTrue(n2 != n3)
        self.assertTrue(n1 == n3)


class HeapTest(unittest.TestCase):
    def setUp(self):
        self.h = MinHeap([HeapNode(0,4,0),
                          HeapNode(1,3,1),
                          HeapNode(2,5,2),
                          HeapNode(4,6,4),
                          HeapNode(5,1,5),
                          HeapNode(6,0,6),
                          HeapNode(3,2,3),
                          HeapNode(7,7,7)])

    def test_build_min_heap(self):
        self.h.build_min_heap()
        self.assertEqual(map(lambda x: x.key, self.h.heap), [0,1,2,6,3,5,4,7])

    def test_heap_decrease_key(self):
        self.h.build_min_heap()
        self.h.heap_decrease_key(5, 0)
        self.assertEqual(map(lambda x: x.key, self.h.heap), [0,1,0,6,3,2,4,7])


class GraphTest(unittest.TestCase):
    def test_dijkstra(self):
        g = Graph({
        0 : [(1, 1), (2, 4)],
        1 : [(3, 6), (2, 1)],
        2 : [(3, 1)],
        3 : []
        })
        g.dijkstra(0)
        self.assertEqual(g.node_map[2].key, 2)


if __name__ == "__main__":
    unittest.main()
