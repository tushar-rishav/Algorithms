def main():
	t=input()
	while t:
		X,Y,Z=map(float,raw_input().split())
		A=(X-Y+Z)/2
		B=(X-Z+Y)/2
		C=(Z-X+Y)/2
		print "%.2f" %(6*(A*B+B*C+C*A))


		t-=1

if __name__=="__main__":
	main()