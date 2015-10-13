from sys import stdin
def fibo(a,b,n):
	for i in xrange(3,n+1):
		c=pow(b,2)+a
		a=b
		b=c
	return b	

if __name__=="__main__":
	a,b,n=map(int,stdin.readline().split())

	print fibo(a,b,n)	
	