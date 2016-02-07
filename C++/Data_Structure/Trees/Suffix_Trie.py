from pprint import pprint
class SuffixTrie(object):

	"""Create a SuffixTrie"""
	ROOT = {}
	def __init__(self, arg):
		arg += "@"
		for n in xrange(len(arg)):
			cur = SuffixTrie.ROOT
			for c in arg[n:]:
				if c not in cur:
					cur[c] = {}
				cur = cur[c]
		pprint(SuffixTrie.ROOT)

	def traverse(self, s):
		"""
			Return node at the end of Path or None
			if no Path exists
		"""
		cur = SuffixTrie.ROOT 
		for c in s:
			if c not in cur:
				return None
			cur = cur[c]
		return cur

	def findSubstring(self, s):
		""" Return true iff s appears as substring to arg """
		return self.traverse(s) is not None

	def findSuffix(self, s):
		""" Return true iff s appears as suffix to arg """
		node = self.traverse(s)
		return node is not None and "@" in node		

if __name__ == "__main__":
	n = int(raw_input())
	while n:
		tree = SuffixTrie(raw_input())
		#tree = SuffixTrie(''.join(reversed(raw_input())))
		n -= 1
	while True:
		s = raw_input(">")
		print tree.findSubstring(s),tree.findSuffix(s)