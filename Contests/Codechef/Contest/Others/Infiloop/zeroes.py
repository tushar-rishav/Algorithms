#! /usr/bin/env python

def main():
    t=input()
    while t:
    	n_5=0
    	n=input()
    	for i in range(1,n+1):
    		j=i
    		while not (j%5):
    			j/=5
    			n_5+=i
    	print n_5
    	
    	t-=1
    
if __name__=="__main__":
    main()
