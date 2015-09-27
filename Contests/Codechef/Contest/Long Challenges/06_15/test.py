import itertools
from sys import stdin,exit
def C(n,r):
	if r==0:
		return 1;
	else: 
		return C(n-1,r-1) * n / r

def substrings(x):
	d={}
	for i, j in itertools.combinations(xrange(len(x)+1), 2):
		st=x[i:j]
		if d.has_key(st):
			d[st]+=1
		else:
			d[st]=1
	return d
def main():
	try:
		MOD= pow(10,9)+7
		t=map(int,stdin.readline().split())
		t=t[0]
		while t:
			n,q=map(int,stdin.readline().split())
			s=raw_input()
			d=substrings(s)
			while q:
				k=map(int,stdin.readline().split())
				k=k[0]
				ways=0
				for key,value in d.iteritems():
					if value>=k:
						ways+=C(value,k)
				print ways%MOD
				q-=1

			t-=1
		exit(0)
	except EOFError,IndexError:
		pass
	




if __name__=="__main__":
	main()
