#! /usr/bin/env python
def main():
	t=input()
	while t:
		ti = raw_input()
		minu=(ord(ti[3])*10+ord(ti[4]))-ord('0')
		hr=(ord(ti[0])*10+ord(ti[1]))-ord('0')
		if hr>12:
			hr-=12
		h=0.5*(hr*60+minu)
		a=minu*6-h
		if not(a%5):
			print "YES"
		else:
			print "NO"	
		
		t-=1
		
    	

if __name__=="__main__":
    main()
