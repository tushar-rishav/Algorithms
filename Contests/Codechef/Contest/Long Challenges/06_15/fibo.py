import time
def fibo(n):
	i=3
	l=[0,1,1]
	if n>2:
		while i<=n:
			l[i%3]= l[(i-1) % 3] + l[(i-2) % 3]
			i+=1
	return l[n%3]
if __name__=="__main__":
	n=input()
	start=time.time()
	print fibo(n)
	print time.time()-start
