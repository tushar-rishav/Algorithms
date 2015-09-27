#! /usr/bin/env python

def main():
    t=input()
    neg=0
    prod=1
    n=map(int,raw_input().split())
    sorted(n)
    for i in range(0,len(n)):
    	if n[i]>0:
    		pos=i
    		break
    	neg+=1
    if neg%2:
    	for i in range(0,len(n)):
    		if n[i]:
    			prod*=n[i]
    	print prod
    if neg>0 and not(neg%2):
    	for i in range(0,len(n)):
    		if i!=pos-1 and num[i]:
    			prod*=num[i]
    	print prod							
    
    if not neg:
    	print n[0]
    	
    
    
    
if __name__=="__main__":
    main()
