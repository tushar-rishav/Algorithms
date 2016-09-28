#! /usr/bin/env python

def main():
	d_key={"1":" ","2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz","0":" "}
	n=input()
	t=n
	count=0
	op=""
	while t: 
		a="".join(str(map(int, raw_input().split())))
		a=a[1:len(a)-1]
		tmp=a[0]
		for i in range(1,len(a)):
			if a[i]==a[i-1]:
				count+=1
				if i==len(a)-1:
					count+=1
			else:
				key=d_key[a[i-1]]
				op+=key[((count)%len(key))]
				count=0
				if i==len(a)-1:
					key=d_key[a[i]]
					op+=key[0]
						
			
		print op
		op=""		
				
		
		t-=1
	
	
if __name__=="__main__":
    main()
