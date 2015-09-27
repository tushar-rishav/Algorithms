#! /usr/bin/env python

def main():
    r=list()
    pt=list()
    nm=list()
    d={}
    i=0
    m=input()
    while m:
    	namePt=raw_input()
    	r.append(namePt)
    	m-=1
    
    for it in r:
    	name,point=it.split(' ')
    	point=ord(point)-ord('0')
    	nm.append(name)
    	pt.append(point)
    	
    	
    maxPt=max(pt)
    
    for n in nm:
    	if d.has_key(n):
    		d[n]+=pt[i]
    		i+=1
    		if d[n]==maxPt:
    			print n
    			break
    			
    	else:
    		d[n]=pt[i]
    		if d[n]==maxPt:
    			print n
    			break
    		i+=1
    			
    
    
if __name__=="__main__":
    main()
