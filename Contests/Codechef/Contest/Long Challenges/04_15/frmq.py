#! /usr/bin/env python

def main():
    n=input()
    a=list()
    i=list()
    a=map(int, raw_input().split())
    i=map(int, raw_input().split())
    sm=0
    while i[0]:
    	l=min(i[1],i[2])
    	u=max(i[1],i[2])
    	sm+=max(a[l:u+1])
    	i[1]=(i[1]+7)%(n-1)
    	i[2]=(i[2]+11)%n
    	i[0]-=1
    print sm	

if __name__=="__main__":
    main()
