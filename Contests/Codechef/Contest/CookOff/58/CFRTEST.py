#! /usr/bin/env python
from sys import stdin,exit
def main():
	t=input()

	while t:
		n=map(int,raw_input())
		days=map(int,stdin.readline().split())
		s=sorted(days)
		d={}
		for i in s:
			if not d.has_key(i):
				d[i]=1
			else:
				d[i]+=1

		print len(d)			
		t-=1

	exit(0)	






if __name__=="__main__":
	main()	