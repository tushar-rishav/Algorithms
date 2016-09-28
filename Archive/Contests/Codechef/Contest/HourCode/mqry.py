from sys import stdin,exit
import heapq

def main():
	n,q=map(int,stdin.readline().split())
	l=map(int,stdin.readline().split())
	while q:
		x,y=map(int,stdin.readline().split())
		m=l[x:y+1]
		heapq.heapify(m)
		print m[-1]-m[0]



		q-=1
	exit(0)



if __name__=="__main__":
	main()
