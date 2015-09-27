from sys import stdin,exit
import operator
def main():
	t=input()

	while t:
		inp=stdin.readline().split()
		d={}
		for i in inp:
			if not d.has_key(i):
				d[i]=1
			else:
				d[i]+=1
			f=sorted(d.items(), key=operator.itemgetter(1))
			
			lis=list()
			st=''
			for i in f:
				lis.append( list(i) )

			l=len(f)	
			m=0
			for q in range(l):
				q+=1
				for i in range(lis[l-q-1][1]):
					if lis[l-m-1][1]:
						st+=lis[l-q-1][0]+lis[l-m-1][0]
						lis[l-q-1][1]-=1
						lis[l-m-1][1]-=1
						if not lis[l-m-1][1]:
							m+=1
			if not lis[l-m-1][1]:
				print -1
			else:
				print st					




					


		t-=1

	exit(0)

if __name__=="__main__":
	main()				

