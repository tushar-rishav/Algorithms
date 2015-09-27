from sys import stdin

def main():
	t=input()
	while t:
		print sum(map(int,stdin.readline().split()))
		t-=1

if __name__=="__main__":
	main()