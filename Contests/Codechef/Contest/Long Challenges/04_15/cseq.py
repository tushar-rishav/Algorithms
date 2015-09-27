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
    m=list()
    while t:
    	n=map(int, raw_input().split())
    	p=n[2]-n[1]+1
    	sm=(nCr(n[0]+p,min(n[0]+p,p))-1)%(10**6+3)
    	
    	print sm
    	t-=1
    
if __name__=="__main__":
    main()
