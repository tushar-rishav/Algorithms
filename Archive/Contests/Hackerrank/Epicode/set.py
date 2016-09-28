from sys import stdin,exit

def main():
	n,s,m=map(int,stdin.readline().split())
	s_l=[]
	a=[0 for i in xrange(n)]	# faster than list()
	mod=1000000009
	while s:
		Si=map(int,stdin.readline().split())
		s_l.append( [Si[0],Si[1:] ] )
		s-=1
	while m:
		q=map(int,stdin.readline().split())
		if q[0]==1:
			t=q[2]
			for i in s_l[q[1]-1][1]:
				a[i-1]+=t
		elif q[0]==2:
			sm=0
			for i in s_l[q[1]-1][1]:
				sm+=a[i-1]
			print sm%mod
		elif q[0]==3:
			t=q[3]
			for i in xrange(q[1],q[2]+1):
				a[i-1]+=t
		else:
			print sum(a[q[1]-1:q[2]])%mod

		m-=1


			



if __name__=="__main__":
	main()