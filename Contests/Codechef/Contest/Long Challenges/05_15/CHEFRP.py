#! /usr/bin/env python

def main():
    t=input()
    
    while t:
    	n=input()
    	s=map(int, raw_input().split())
    	if min(s)<2:
    		print -1
    	else:
    		print sum(s)-min(s)+2	
    	t-=1
    
if __name__=="__main__":
    main()	
