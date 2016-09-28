from sys import stdin,exit
def countPattern(nStr):
	pattern = '101'
	count =0
	flag=True
	start=0
	while flag:
		a = nStr.find(pattern,start)  # find() returns -1 if the word is not found, 
		if a==-1:          #if pattern not found set flag to False
			flag=False
		else:               # if word is found increase count and set starting index to a+1
			count+=1        
			start=a+1
	return count

def main():
	t=input()
	while t:
		r,k=map(int,stdin.readline().split())
		c=0
		p=2**k
		for i in range(p,r+1):
			if countPattern(str(bin(i)[2:]))>=k:
				c+=1
		print c
		c=0
		t-=1

	#exit(0)
if __name__=="__main__":
	main()
