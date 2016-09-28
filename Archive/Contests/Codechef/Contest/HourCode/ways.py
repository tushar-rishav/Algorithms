from sys import stdin,exit
from itertools import izip
def c(n,r):
	return reduce(lambda x, y: x * y[0] / y[1], izip(xrange(n - r + 1, n+1), xrange(1, r+1)), 1)
def main():
	mod=1000000007
	t=int(raw_input())
	
	while t:
		n,l=map(int,stdin.readline().split())
		print c(n,l)%mod



		t-=1




if __name__=="__main__":
	main()