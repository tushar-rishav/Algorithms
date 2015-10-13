from sys import stdin,exit
 
def main():
	n=int(raw_input())
	a=map(int,stdin.readline().split())
	flag=False
	for i in a:
		if not(i%5):
			while True:
				p=i*4
				if (len(str(i))-len(str(i).rstrip('0')))==(len(str(p))-len(str(p).rstrip('0'))):
					print i
					flag=True
					break
					
				else:
					i=p
			if not flag:
				print i
 
		else:
			print i
		flag=False
	exit(0)
 
 
if __name__=="__main__":
	main()