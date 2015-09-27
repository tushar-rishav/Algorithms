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
def fibonacci(n):
    return _fib(n)[0]


def _fib(n):
    if n == 0:
        return (0, 1)
    else:
        a, b = _fib(n // 2)
        c = a * (b * 2 - a)
        d = a * a + b * b
        if n % 2 == 0:
            return (c, d)
        else:
            return (d, c + d)
def main():
    n=input()
    i=0
    p=power(10,13)
    while 1:
    	el=fibonacci(i)%p
    	
    	if el==n:
    		print i
    		break
    	elif el>n:
    		print -1
    		break
    	i+=1		
    
    
if __name__=="__main__":
    main()            
