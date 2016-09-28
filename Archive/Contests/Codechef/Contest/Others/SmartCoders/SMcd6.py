#! /usr/bin/env python

def main():
	t=input()
	
	while t:
		a,b,m=map(int, raw_input().split())
		k= (b-a)/m
		if k!=1:
			print k
		else:
			print 0	
			
		t-=1
		
	
	
if __name__=="__main__":
    main()
