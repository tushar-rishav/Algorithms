"""
    Trie implementation using Python dictionary.
"""
import unittest

class Node:
    __slots__ = ['label', 'data', 'children', 'words_count'] # save memory
    def __init__(self, label=None, data=None):
        self.label = label
        self.data = data
        self.children = dict()
        # the number of words this prefix is part of
        self.words_count = 0

    def addChild(self, key, data=None):
        if not isinstance(key, Node):
            self.children[key] = Node(key, data)
        else:
            self.children[key.label] = key

    def __getitem__(self, key):
        return self.children[key]

class Trie:
    def __init__(self):
        self.head = Node()

    def __getitem__(self, key):
        return self.head.children[key]

    def add(self, word):
        current_node = self.head
        word_finished = True

        for i in range(len(word)):
            if word[i] in current_node.children:
                current_node = current_node.children[word[i]]
                current_node.words_count += 1
            else:
                word_finished = False
                break

        if not word_finished:
            while i < len(word):
                current_node.addChild(word[i])
                current_node = current_node.children[word[i]]
                current_node.words_count += 1
                i += 1

        current_node.data = word

    def has_word(self, word):
        if word == '':
            return False
        if word == None:
            raise ValueError('Trie.has_word requires a not-Null string')

        current_node = self.head
        exists = True
        for letter in word:
            if letter in current_node.children:
                current_node = current_node.children[letter]
            else:
                exists = False
                break

        if exists:
            if current_node.data == None:
                exists = False

        return exists

    def start_with_prefix(self, prefix):
        """ Returns a list of all words in tree that start with prefix """
        words = list()
        if prefix == None:
            raise ValueError('Requires not-Null prefix')

        top_node = self.head
        for letter in prefix:
            if letter in top_node.children:
                top_node = top_node.children[letter]
            else:
                return words

        if top_node == self.head:
            queue = [node for key, node in top_node.children.iteritems()]
        else:
            queue = [top_node]

        # BFS under prefix, BFS will return
        # a list of words ordered by increasing length
        while queue:
            current_node = queue.pop()
            if current_node.data != None:
                words.append(current_node.data)

            queue = [node for key,node in current_node.children.iteritems()] + queue

        return words

    def count_prefix(self, prefix):
        """
        Count the words that have given prefix.
        `start_with_prefix` returns list of all such words. This approach is more
        efficient when we just need the count of words that share the same prefix.
        """
        curr = self.head
        for c in prefix:
            next_node = curr.children.get(c, None)
            if next_node is None:
                return 0  # prefix not found
            curr = next_node

        return curr.words_count

    def getData(self, word):
        """ This returns the 'data' of the node identified by the given word """
        if not self.has_word(word):
            raise ValueError('{} not found in trie'.format(word))

        current_node = self.head
        for letter in word:
            current_node = current_node[letter]

        return current_node.data


class TestTrie(unittest.TestCase):
    def setUp(self):
        self.trie = Trie()
        words = 'hackerrank hackfest'
        for word in words.split():
            self.trie.add(word)

    def test_has_word(self):
        self.assertFalse(self.trie.has_word('hack'))

    def test_count_prefix(self):
        self.assertEqual(2, self.trie.count_prefix('hack'))
        self.assertEqual(0, self.trie.count_prefix('hacky'))
        self.assertEqual(1, self.trie.count_prefix('hacke'))

    def test_start_with_prefix(self):
        self.assertEqual(['hackfest', 'hackerrank'], self.trie.start_with_prefix('hack'))
        self.assertEqual([], self.trie.start_with_prefix('hacky'))


if __name__ == '__main__':
    unittest.main()
