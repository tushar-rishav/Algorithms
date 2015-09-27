from sys import stdin,exit

def main():
	t=input()
	while t:
		n=map(int,raw_input().split())
		m=map(int,stdin.readline().split())
		i=0
		s_mem=m[0]
		while i<n[0]-1:
			if m[i+1]-m[i]>0:
				s_mem+=m[i+1]-m[i]
			i+=1
		print s_mem

		t-=1
	exit(0)
if __name__=="__main__":
	main()




