#! /usr/bin/env python
def main():
	t=input()
	
	
	while t:
		n=map(int,raw_input().split())
		if not (n[1]%n[0]):
			print "CORRECT"
		else:
			print "WRONG"	
		
		t-=1
    	

if __name__=="__main__":
    main()
