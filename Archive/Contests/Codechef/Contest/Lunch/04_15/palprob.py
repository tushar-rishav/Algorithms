#! /usr/bin/env python
class const:
	class ConstError(TypeError): pass
	def __setattr__(self,name,value):
		self.__dict__[name]=value
        
def power(base, exponent):
	if not exponent:
		return 1
	remaining_multiplicand = 1
	result = base
	while exponent > 1:
		remainder=exponent % 2
		if remainder > 0:
			remaining_multiplicand = remaining_multiplicand * result
		exponent = (exponent - remainder) / 2
		result = result * result

	return result * remaining_multiplicand
def gcd(i,n):
	for j in range(2,i+1):
		if not(i%j) and not(n%j):
			return j
	return 1		
			
def main():
	t=input()
	su=0
	const.mod=power(10,9)+7
	while t:
		n,k=map(int,raw_input().split())
		su+=1
		if not(n%2):
			for i in range(3,n,2):
				g=gcd(i,n)
				if g==1:
					su+=(power(i,k)%const.mod)
					
		else:	
			for i in range(2,n):
				g=gcd(i,n)
				if g==1:
					su+=(power(i,k)%const.mod)
		print su
		su=0			
		
		
		
		t-=1
		
	
	
if __name__=="__main__":
    main()
