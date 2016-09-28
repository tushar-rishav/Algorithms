from sys import stdin,exit
def main():
	q=input()
	while q:
		n,t=map(int,stdin.readline().split())
		while t:
			if n%2:
				n-=(n+1)/2
			else:
				n-=n/2
			n-=n//4
			t-=1
		print n
		q-=1
	#exit(0)


if __name__=="__main__":
	main()