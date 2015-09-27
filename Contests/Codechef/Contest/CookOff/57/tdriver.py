#! /usr/bin/env python

def main():
    t=input()
    
    while t:
    	n=input()
    	x=list(xrange(n))
    	y=list(xrange(n))
    	a,b=map(int, raw_input().split())
    	for i in range(0,n):
    		x[i],y[i]=map(int, raw_input().split())
    		
    	sum=0
    	for i in range(0,n-1):
    		for j in range(i+1,n):
    			sum+=max(a*abs(x[i]-x[j]),b*abs(y[i]-y[j]))
    			
    	print sum
    	
    	t-=1
    
if __name__=="__main__":
    main()
