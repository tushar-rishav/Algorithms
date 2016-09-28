from collections import Counter
from sys import stdin,exit
from itertools import izip
def c(n,r):
	return reduce(lambda x, y: x * y[0] / y[1], izip(xrange(n - r + 1, n+1), xrange(1, r+1)), 1)

def main():
	n=int(raw_input())
	s=Counter(raw_input())
	sm=0
	l=0
	for i in s:
		sm+=c(s[i],2)
		l+=s[i]
	print sm+l

if __name__=="__main__":
	main()