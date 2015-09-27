#! /usr/bin/env python
import math
def is_prime(n):
	if n % 2 == 0 and n > 2:
		return False
	for i in range(3, int(math.sqrt(n)) + 1, 2):
		if n % i == 0:
			return False
	return True
				
def main():
	t=input()
	while t:
		a,b=map(int, raw_input().split())
		all_div=False
		for i in range(1,b+1):
			if not(b%i):
				if is_prime(i) and a%i:
					print "NO"
					all_div=True
					break
		if not all_div:
			print "YES"			
		t-=1
    
if __name__=="__main__":
    main()	
