#! /usr/bin/env python
import math
def power(x,y):
	
	if( y == 0):
		return 1
	temp = power(x, y/2)
	if y%2 == 0:
		return temp*temp
	else:
		return x*temp*temp


def main():
    t=map(int, raw_input().split())
    MOD=math.pow(10,9) + 7
    while t[0]:
    	sm=0
    	n=map(int, raw_input().split())
    	Ma=map(int, raw_input().split())
    	sz=len(Ma)
    	for i in range(sz):
			sm+=( (Ma[i]-Ma[sz-i-1]) * (power(2,sz-i-1)-1) );

    	print long(abs(sm)%MOD)
    	sm=0
    	t[0]-=1
    
if __name__=="__main__":
    main()    
