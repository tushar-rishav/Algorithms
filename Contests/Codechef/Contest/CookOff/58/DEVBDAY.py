#! /usr/bin/env python
from sys import stdin,exit
def main():
	t=input()

	while t:
		n=map(int,raw_input())
		f=map(int,stdin.readline().split())
		r=map(int,stdin.readline().split())
		repeat=0
		max_amt=0
		c=0		
		for i in f:
			if r[i-1]+r[c] >0:
				if f[i-1]!=(c+1):
					max_amt+=(r[i-1]+r[c])

				else:
					repeat+=r[i-1]+r[c]
			c+=1		
		max_amt+=(repeat/2)			
		print max_amt			
		t-=1

	exit(0)	






if __name__=="__main__":
	main()	