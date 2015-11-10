#! /usr/bin/env python
from math import factorial
 
 
def main():
    t=input()
    while t:
    	n=input()
    	print factorial(n)
    	t-=1
 
if __name__=="__main__":
    main()