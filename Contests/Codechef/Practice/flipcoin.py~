#! /usr/bin/env python
from itertools import repeat
from string import maketrans
def main():
    n,q=map(int, raw_input().split())
    inp=list()
    arr=list(repeat('0',n))
    while q:
    	inp=map(int, raw_input().split())
    	
    	if inp[0]:
    		print arr[inp[1]:inp[2]+1].count('1')
    	else:
    		arr[inp[1]:inp[2]+1]=list(''.join(str(e) for e in arr[inp[1]:inp[2]+1]).translate(maketrans("10","01")))
    		
    	q-=1

if __name__=="__main__":
    main()
