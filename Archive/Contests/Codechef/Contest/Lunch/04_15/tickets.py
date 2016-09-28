#! /usr/bin/env python

def main():
	t=input()
	
	while t:
		s=raw_input()
		c=True
		
		a=s[::2]
		b=s[1::2]
	
		if (len(a)-a.count(a[0])<=len(a)-2) and (len(b)-b.count(b[0])<=len(b)-2):
			c=True
		else:
			c=False	
		
		if not c:
			print "NO"
		else:
			print "YES"
						
				
					
		t-=1
		
	
	
if __name__=="__main__":
    main()
