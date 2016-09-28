from collections import defaultdict
import copy
import math
import random
import unittest


class AdjElement:
    def __init__(self, node, edge):
        """
        :param node: A list of given nodes.
        :param edge: A list of given adjacent elements.
        """
        self.node = node
        self.edge = edge

    def merge(self, other):
        # Merge vertices ignoring self loops.
        self.node += other.node
        self.edge = [i for i in self.edge + other.edge if i not in self.node]

    def __repr__(self):
        return "Adjacency(node = {node}, edge = {edge})".format(node=self.node,
                                                                edge=self.edge)

class Graph:
    """
    A list of AdjElements.
    """
    def __init__(self):
        self.adj_list = []
        with open('graph_min_cut.txt', 'r') as inp_data:
            for line in inp_data:
                l_split = line.split()
                self.adj_list.append(AdjElement(node=[int(l_split[0])],
                                                edge=map(int, l_split[1:])))


class MinCutGraph:
    def __init__(self):
        self.graph = Graph().adj_list

    def cut(self, graph):
        if len(graph) == 2:
            return graph
        else:
            rand_pick = random.choice(graph)
            merge_node = random.choice(rand_pick.edge)
            # check if the `merge_node` can be merged.
            merge_pick = [i for i in graph if merge_node in i.node]
            rand_pick.merge(merge_pick[0])
            graph.remove(merge_pick[0])
            return self.cut(graph)


    def karger_min_cut(self):
        """
        A randomized algorithm to compute a minimum cut of a connected graph.
        """
        graph = self.graph
        trial_num = int(math.pow(len(graph), 1) * math.log(len(graph)))
        min_cross = float('inf')
        print trial_num
        for i in range(trial_num):
            print "Trial: {}".format(i)
            trial = self.cut(copy.deepcopy(graph))
            cut_cross = len(trial[0].edge)
            if cut_cross < min_cross:
                min_cross = cut_cross
                out = trial
        return out, min_cross


class MinCutGraphTest(unittest.TestCase):
    def test_karger_min_cut(self):
        graph = MinCutGraph()
        self.assertEqual(graph.karger_min_cut()[1], 17)


if __name__ == "__main__":
    unittest.main()
