def main():
	t=input()
	while t:
		n=int(raw_input())
		r=1
		for i in range(2,n+1):
			r=((i*r)/gcd(i,r))
			
		print r
		t-=1




def gcd(a,b):
	if b == 0:
		return a
	else:
		return gcd(b,a % b)

if __name__=="__main__":
	main()