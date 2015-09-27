def main():
	t=input()
	while t:
		n=int(raw_input())
		s1= n*(n+1)/2
		s2=s1*(2*n+1)/3
		print s1*s1-s2
		t-=1




if __name__=="__main__":
	main()