from sys import stdin

def main():
	r,c=map(int,stdin.readline().split())
	val=10*(r-1)/2 + 2*(c-1)
	if r%2:
		print val
	else:
		print val-4

if __name__=="__main__":
	main()