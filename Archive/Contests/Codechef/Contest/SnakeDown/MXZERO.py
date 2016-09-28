from sys import stdin,exit
def main():
	t=input()

	while t:
		p=map(int,raw_input().split())
		A=map(int,stdin.readline().split())
		N=A.count(1)
		M=A.count(0)
		ways=0
		if (N%2) and N:
			ways+=N
		else:
			ways+=M
		print ways
		t-=1
	exit(0)

if __name__=="__main__":
	main()