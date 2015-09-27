def main():
	t=int(raw_input())
	while t:
		pair=[0,0]
		n=int(raw_input())
		sm=0
		s=0
		if n>1:
			sm=2
			if n>=5:
				pair[-1]=5
				pair[-2]=3
				
				while True:
					s=pair[-1]+pair[-2]
					if s>n:
						break
					sm+=s
					pair[0]=s+pair[-1]
					pair[1]=s+pair[0]
				print sm

			elif n>=2:
				print 2
		else:
			print 0
		t-=1
				



if __name__=="__main__":
	main()