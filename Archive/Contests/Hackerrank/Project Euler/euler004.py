def main():
	t=input()
	while t:
		n=int(raw_input())
		i=100
		p=1
		m=1
		while i<1000:
			j=i
			while j<1000:
				p=i*j
				if p<n:
					if p==int(str(p)[::-1]):
						if p>m:
							m=p
				
				j+=1
			i+=1
		print m




		t-=1



if __name__=="__main__":
	main()