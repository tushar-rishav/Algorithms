def main():
	t=input()
	while t:
		n=int(raw_input())
		
		k=(n-(n%3))/3
		p=(n-(n%5))/5
		c=(n-(n%15))/15
		m=	(3*k*(k+1)/2)	+	(5*p*(p+1)/2)	- (15*c*(c+1)/2)
		if not(n%3 or n%5):
			m-=n
		elif not(n%3) or not(n%5):
			m-=n
		print m
		
		t-=1



if __name__=="__main__":
	main()