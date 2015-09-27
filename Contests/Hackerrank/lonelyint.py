from sys import stdin,exit
def main():
	n=input()
	a=map(int,stdin.readline().split())
	a.sort()
	for i in range(0,len(a),2):
		if i==len(a)-1:
			print a[i]
			break
		if a[i]^a[i+1]:
			print a[i]
			break


if __name__=="__main__":
	main()