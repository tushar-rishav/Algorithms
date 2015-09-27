from sys import stdin
from time import time
def square(n):			#O(logn)
	n=int(n)
	if(n==0):
		return 0;
 
	if(n < 0):
		n = -n
 	x = n>>1
 	if (n&1):
 		return ((square(x)<<2) + (x<<2) + 1)
	else:
		return (square(x)<<2)



def main():
	start=time()
	n=int(raw_input())
	r=sorted(map(int,stdin.readline().split()))
	m=int(raw_input())
	i=0
	c={}
	while i<m:
		c[i]=map(square,stdin.readline().split())
		i+=1
	r=map(square,r)
	q=0
	for cd in c.values():
		for i in xrange(n):
			if (cd[0]+cd[1]-r[i])^((cd[2]+cd[3]-r[i]))<0:
				q+=1
			else:
				i=n
	print q
	print time()-start


if __name__=="__main__":
	main()