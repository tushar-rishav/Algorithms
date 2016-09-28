#! /usr/bin/env python
import copy
def main():
    num=list()
    match=list()
    f=list()
    
    n,m=map(int,raw_input().split())
    num=map(int,raw_input().split())
  
   
    
    
    while m:
    	el=input()
    	#matchCpy=copy.deepcopy(match)
    	f=set(num[el:])
    	print len(f)	
    	m-=1
    
if __name__=="__main__":
    main()
