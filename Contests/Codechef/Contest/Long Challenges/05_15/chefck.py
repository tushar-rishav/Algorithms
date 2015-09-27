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
	n,k,q=map(int, raw_input().split())
	a, b, c, d, e, f, r, s, t, m,a1=map(int, raw_input().split())
	L1, La, Lc, Lm, D1, Da, Dc,Dm=map(int, raw_input().split())
	MOD=math.pow(10,9) + 7
	Ar=[None]*(n+1)
	Ar[1]=a1
	
	for x in range(2,n+1):
		po=power(Ar[x-1],2)
		if power(t,x)%s <= r:        #Here t^x signifies "t to the power of x"
			Ar[x] = (a*po + b*Ar[x-1] + c) % m
		else:
			Ar[x] = (d*po + e*Ar[x-1] + f) % m
	sm,iPd=0,1
	for i in range(1,q+1):
		L1 = (La * L1 + Lc) % Lm
		D1 = (Da * D1 + Dc) % Dm 
		L = L1 + 1;
		R = min(L + k - 1 + D1, n);
    	
		mEl=min(Ar[L:R+1])
		sm+=mEl;
		if iPd*mEl>MOD:
			iPd=((iPd%MOD)*(mEl%MOD))%MOD
		else:
			iPd*=mEl
    
	print sm,long(iPd%MOD)
    	
if __name__=="__main__":
    main()    