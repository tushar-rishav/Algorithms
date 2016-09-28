from sys import stdin,exit

def main():
	n,p,x=map(int,stdin.readline().split())
	a=map(int,stdin.readline().split())
	m=max(a)	#O(nlogn)
	l=a.index(m)
	big=0
	ind=0
	for i in xrange(l+1):
		lef=a[i]*(p-(i-1)*x)
		rt=a[l-i]*(p-(l-i-1)*x)
		if lef>rt:
			if lef>big:
				big=lef
				ind=i
		else:
			if rt>big:
				big=rt
				ind=l-i
	print ind+1






if __name__=="__main__":
	main()