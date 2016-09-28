from sys import stdin,exit
def sum_digits(n):
	s = 0
	while n:
		s += n % 10
		n /= 10
		if s/10:
			s=sum_digits(s)

	return s
def main():
	t=input()

	while t:
		m=map(int,raw_input().split())
		sm=0
		while m[0]:
			a=map(int,stdin.readline().split())
			sm+=sum_digits(a[0]*a[1])
			if sm/10:
				sm=sum_digits(sm)
			m[0]-=1
		print sm
		t-=1

	exit(0)

if __name__=="__main__":
	main()