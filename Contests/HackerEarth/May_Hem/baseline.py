from sys import stdin,exit
def med(x):
	m,r= divmod(len(x),2)
	if r:
		return sorted(x)[m]
	return sum(sorted(x)[m-1:m+1])/2

def main():
	t=input()

	while t:
		n,k=map(int,raw_input().split())
		c=n
		s=list()
		while c:
			s.append(map(ord,stdin.readline()[:-1]))
			c-=1
		s=zip(*s)
		for i in range(len(s)):
			s[i]=list(s[i])
		st=str()
		for i in s:
			st+=chr(int(med(i)))
		print st
		t-=1
	print

	exit(0)

if __name__=="__main__":
	main()