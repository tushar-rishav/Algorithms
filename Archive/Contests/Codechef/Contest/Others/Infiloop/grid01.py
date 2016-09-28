#! /usr/bin/env python

def main():
    t=input()
    while t:
    	n,m=map(int, raw_input().split())
    	print 12+(n+m-4)*10 + (n-2)*(m-2)*8
    	t-=1
    
if __name__=="__main__":
    main()
