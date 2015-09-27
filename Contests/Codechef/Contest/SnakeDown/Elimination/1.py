from sys import stdin,exit
from copy import copy
#from time import time
def ispalin(x):
	l=len(x)
	return all(x[a]==x[-a-1] for a in xrange(l>>1))
def main():
	
	r=stdin.readline().split()
	r=list(r[0])
	
	q=int(raw_input())
	
	while q:
		#start=time()
		i,j,k,l=map(int,stdin.readline().split())
		r_c=copy(r)	#temp cpy of r
		r_c[i-1:j]=list(reversed(r_c[i-1:j]))
		if ispalin(r_c[k-1:l]):
			print "Yes"
		else:
			print "No"
		#print time()-start
		q-=1



	exit()
if __name__=="__main__":
	main()