#! /usr/bin/env python

def main():
    t=input()
    
    while t:
    	ign=list()
    	tra=list()
    	n,m,k=map(int, raw_input().split())
    	big=list(xrange(n+1))
    	big=big[1:]
    	ign=map(int, raw_input().split())
    	tra=map(int, raw_input().split())
    	print len(set(ign).intersection(tra)),
    	print len( set(list(set(big)-set(ign))).intersection(list(set(big)-set(tra))))
    	
    	
    	t-=1
    
if __name__=="__main__":
    main()
