from sys import exit,stdin
 
def main():
	t=int(raw_input())
	while t:
		n,k=map(int,stdin.readline().split())
		a=map(int,stdin.readline().split())
		pc=0
		left=0
		for i in a:
			#if i!=k:
			if left>0:
				dif=i-left
				if dif>0:
					if dif%k:
						pkg=(dif/k+1)
					else:
						pkg=dif/k
					pc+=pkg
					elem=pkg*k
					if i!=elem:
						left=(elem)-i-1
					else:
						left=0
					
				elif not dif:
					left=0
				else:
					left-=i
			elif not left:
				if i%k:
					pkg=(i/k+1)
				else:
					pkg=i/k
				pc+=pkg
				elem=pkg*k
				if i!=elem:
					left=(elem)-i-1
				else:
					left=0
		print pc
 
 
		t-=1
	exit(0)
 
 
if __name__=="__main__":
	main() 