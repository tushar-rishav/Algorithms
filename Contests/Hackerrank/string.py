from sys import stdin,exit
import collections

class OrderedSet(collections.MutableSet):

	def __init__(self, iterable=None):
		self.end = end = [] 
		end += [None, end, end]         
		self.map = {}                   
		if iterable is not None:
			self |= iterable

	def __len__(self):
		return len(self.map)

	def __contains__(self, key):
		return key in self.map

	def add(self, key):
		if key not in self.map:
			end = self.end
			curr = end[1]
			curr[2] = end[1] = self.map[key] = [key, curr, end]

	def discard(self, key):
		if key in self.map:        
			key, prev, next = self.map.pop(key)
			prev[2] = next
			next[1] = prev

	def __iter__(self):
		end = self.end
		curr = end[2]
		while curr is not end:
			yield curr[0]
			curr = curr[2]

	def __reversed__(self):
		end = self.end
		curr = end[1]
		while curr is not end:
			yield curr[0]
			curr = curr[1]

	def pop(self, last=True):
		if not self:
			raise KeyError('set is empty')
		key = self.end[1][0] if last else self.end[2][0]
		self.discard(key)
		return key

	def __repr__(self):
		if not self:
			return '%s()' % (self.__class__.__name__,)
		return '%s(%r)' % (self.__class__.__name__, list(self))

	def __eq__(self, other):
		if isinstance(other, OrderedSet):
			return len(self) == len(other) and list(self) == list(other)
		return set(self) == set(other)
def np():
	print "NOT POSSIBLE"

def main():
	
	s1=raw_input()
	s2=raw_input()
	l1=len(s1)
	l2=len(s2)
	
	sl1=list(s1)
	sl2=list(s2)

	as1_i=sl1.index("*")
	as2_i=sl2.index("*")
	cpy_s1=sl1[:]		### copy
	cpy_s2=sl2[:]
	cpy_s1.pop(as1_i)	### * free strings
	cpy_s2.pop(as2_i)
	
	if l1==l2:
		##### CASE: 1
		##### strings differ only at '*' hence no addition reqd. Just remove the '*' #####
		if cpy_s1==cpy_s2:
				print ''.join(cpy_s1)
				exit(1)
		if as1_i==as2_i:		### both '*' are at same position
			if cpy_s1!=cpy_s2:
				np()
				exit(1)			### ISSUE 1
		else:
			os1=OrderedSet(cpy_s1)
			os2=OrderedSet(cpy_s2)
			uset=os1|os2
			s2_s1=uset-os1
			s1_s2=uset-os2
			
			#print uset,s1_s2,s2_s1
			if as1_i and as2_i:	### * is not in extremes in both strings
				#### CASE:2 
				#### strings differ from each other only at '*' but by only  one character
				match= True
				if len(s1_s2)<=1 and len(s2_s1)<=1:
					for i in xrange(l1):	### when strings do not have same order internally and string differ just by one char
						if not(sl1[i]=="*" or sl2[i]=="*"):
							if sl1[i]!=sl2[i]:
								np()
								match=False
								break					
					if match: 
						if as1_i==as2_i:
							sl1[as1_i]='Z'
							print ''.join(sl1)
						else:
							tmp=sl1[:]
							sl1[as1_i]=sl2[as1_i]
							sl2[as2_i]=tmp[as2_i]
							print ''.join(sl1)
				else:
					#### CASE:3
					#### Complex case. 
					pass
			else:
				#### CASE:6 when either of '*' lies at index position
				if not(as1_i) and as2_i and as2_i!=l2-1:	### 1st '*' at 0 index and 2nd in btwn
					if ''.join(sl1[as1_i:])!=''.join(sl2[as2_i:]):
						np()
						exit(1)
					else:
						print ''.join(cpy_s2)
						exit(0)
				if not(as2_i)and as1_i and as1_i!=l1-1:	### 2nd '*' at 0 index and 1st in btwn
					if ''.join(sl2[as2_i:])!=''.join(sl1[as1_i:]):
						np()
						exit(1)
					else:
						print ''.join(cpy_s1)
						exit(0)
				if not(as1_i or as2_i):
					### both '*' at 0 index
					if ''.join(cpy_s1)!=''.join(cpy_s2):
						np()
					else:
						pass
				### if both '*'lies at the end HANDLED IN ISSUE 1.
				if not(as1_i) and as2_i==l2-1:	### 1st '*' at 0 index, 2nd '*' at end
					print ''.join(cpy_s2)+''.join(cpy_s1)
				if not(as2_i) and as1_i==l1-1:	### 2nd '*' at 0 index, 1st '*' at end
					print ''.join(cpy_s1)+''.join(cpy_s2)	
						

						
			
	else:
		if as1_i==l1-1 and as2_i==l2-1 and l1-1 and l2-1:	### CASE:4  when both '*' lies at the end and string len is>1
			m=min(as1_i,as2_i)
			for i in xrange(m):
				if sl1[i]!=sl2[i]:
					np()
					exit(1)
			if sl1==m+1:
				print ''.join(cpy_s2)
			else:
				print ''.join(cpy_s1)
			# s=[]
			# sc=[]
			# if as1_i>as2_i:
			# 	l=l1
			# 	s=sl2
			# 	sc=sl1
			# else:
			# 	l=l2
			# 	s=sl1
			# 	sc=sl2
			#s.pop(m)
			#for i in xrange(m,l):
			#	s.append(sc[i])
		if not(as1_i or as2_i):		### CASE:5 when both '*' lies at 0 index
			if l1>1 and l2>1:
				np()
				exit(1)
			else:
				if l1-1:
					print ''.join(cpy_s1)
				else:
					print ''.join(cpy_s2)
		else:
			if as1_i and not(as2_i):	### 1st '*' in btwn and 2nd '*' at 0 index
				if l1>1 and l2>1:
					if ''.join(sl1[as1_i+1:])==''.join(sl2[as2_i+1:]):
						print ''.join(sl1[:as1_i])+''.join(sl2[as2_i+1:])
						exit(0)
				else:
					if l1-1:
						print ''.join(cpy_s1)
						exit(0)
					else:
						print ''.join(cpy_s2)
						exit(0)
			if as2_i and not(as1_i):
				if l1>1 and l2>1:
					if ''.join(sl2[as2_i+1:])==''.join(sl1[as1_i+1:]):	### 2nd '*' in btwn and 1st '*' at 0 index
						print ''.join(sl2[:as2_i])+''.join(sl1[as1_i+1:])
						exit(0)
				else:
					if l2-1:
						print ''.join(cpy_s2)
						exit(0)
					else:
						print ''.join(cpy_s1)
						exit(0)


			

			
			 
		
							
			
		
						

		



if __name__=="__main__":
	main()
