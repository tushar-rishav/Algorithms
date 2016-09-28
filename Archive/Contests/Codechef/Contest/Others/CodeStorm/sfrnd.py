#! /usr/bin/env python
import operator as op
def nCr(n,r):
	r=min(r,n-r)
	if r==0:return 1
	numer=reduce(op.mul,xrange(n,n-r,-1))
	denom=reduce(op.mul,xrange(1,r+1))
	return numer//denom

def main():
    t=input()
    
    while t:
    	n=input()
    	if n<6:
    		print "FIGHT"
    	else:	
    		sm=(nCr(n-1,5))%(10**9+7)
    		print sm
    	
    	t-=1
    
if __name__=="__main__":
    main()
