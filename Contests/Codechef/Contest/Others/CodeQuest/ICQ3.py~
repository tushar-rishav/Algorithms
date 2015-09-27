#! /usr/bin/env python
def main():
	integers=list()
	alpha=list()
	integersPos=list()
	alphaPos=list()
	t=raw_input().split()
	
	while t[0]:
		inpStr=raw_input().split()
		inpStr=list(inpStr[0])
		j=0
		k=0
		for i,val in enumerate(inpStr):
			if ord(val)>47 and ord(val)<58:
				integers.append(val)
    			integersPos.append(i)
    			
    		else:
    			alpha.append(val)
    			alphaPos.append(i)
    			
    	alpha.sort()
    	integers.sort()
    	for m in range(len(integers)):
    		inpStr[integersPos[m]]=integers[m]
    	for p in range(len(alpha)):
    		inpStr[alphapos[p]]=alpha[p]				
    	inpStr=str(inpStr)
    	print inpStr
    	t[0]-=1
    	

if __name__=="__main__":
    main()
