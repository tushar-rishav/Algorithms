from __future__ import division
from math import log,floor

def main():
	l=input()
	r=input()
	max_xor=float("-inf")
	for i in range(l,r+1):
		for j in range(i,r+1):
			# if xor(i,j)>max_xor:
			# 	max_xor=xor(i,j)
			max_xor=max(max_xor,i^j)
	print int(max_xor)

def xor(x,y):
	# when calculating XOR using this mathematical formula the time complexity was very poor. 
	# hence this way should not be used
	b=int(floor(log(x,2))+1)
	return sum(
			[(2**n)*( (floor(x/(2**n))%2 + floor(y/(2**n))%2)%2 ) for n in range(b+1)]
	)
	
if __name__=="__main__":
	main()