from sys import exit,stdin
def ZeroShark(x):
	n = len(x)
	counter = 0
	p=1
	while p<n:
		if x[i] == '0' and x[i - 1] == '0':
			counter+=1
	if counter==1:
		return True
	else:
		return False
		p+=1


def main():
	mod=10**9+7
	t=input()
	while t:
		n=map(int,stdin.readline().split())
		n=n[0]
		bt=0
		binStrings=list()

		l=(2**n)-1
		i=0
		while i<=l:
			binSt=bin(i)[2:]
			r='0'*(n-len(binSt))+binSt
			binStrings.append(r)
			i+=1
		for j in binStrings:
			if ZeroShark(j):
				bt+=1
				if bt>mod:
					bt%=mod

		print bt

		t-=1


	exit(0)

if __name__=="__main__":
		main()
