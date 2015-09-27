from time import time
# function that returns nth Fibonacci number 
def fib(n):   
	F=[[1,1],[1,0] ]
	if (n == 0):
	  return 0
	power(F, n-1)
	return F[0][0]
 
# Optimized version of power() in method 4
def power(F, n):
	if( n == 0 or n == 1):
	    return
	M= [[1,1],[1,0]]	
	power(F, n/2)
	multiply(F, F)	
	if (n%2 != 0):
		multiply(F, M)
 
def multiply(F, M):
	x =  F[0][0]*M[0][0] + F[0][1]*M[1][0]
	y =  F[0][0]*M[0][1] + F[0][1]*M[1][1]
	z =  F[1][0]*M[0][0] + F[1][1]*M[1][0]
	w =  F[1][0]*M[0][1] + F[1][1]*M[1][1]
 
	F[0][0] = x
	F[0][1] = y
	F[1][0] = z
	F[1][1] = w
if __name__=="__main__":
	n=input()
	fib_l=[]
	start=time()
	for i in xrange(1,1000000):
		fib_l.append(fib(n))

	print time()-start