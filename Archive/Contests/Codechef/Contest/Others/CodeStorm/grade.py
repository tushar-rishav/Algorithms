#! /usr/bin/env python
def power(base, exponent):
  	remaining_multiplicand = 1
  	result = base
	while exponent > 1:
    	 remainder=exponent % 2
    	 if remainder > 0:
      		  remaining_multiplicand = remaining_multiplicand * result
    	 exponent = (exponent - remainder) / 2
    	 result = result * result

  	return result * remaining_multiplicand
def main():
	t=input()
	while t:
		n=input()
		res=power(7,n)%(10**9+7)
		print res
		t-=1
    	

if __name__=="__main__":
    main()
