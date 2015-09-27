from collections import Counter
from sys import stdin
def main():
	t=int(raw_input())
	while t:
		c=0
		n=int(raw_input())
		a=Counter(stdin.readline().split())
		for i in a.values():
			if i>1:
				c+=i*(i-1)
		print c
		
		t-=1



if __name__=="__main__":
	main()
