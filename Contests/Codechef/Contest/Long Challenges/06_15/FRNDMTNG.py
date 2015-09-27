from __future__ import division 
from sys import exit,stdin
def main():
	t=input()
	while t:
 		T1,T2,t1 ,t2=map(int,stdin.readline().split())
 		prod=T1*T2
 		if not(t1 or t2):
 			print 0
 		else:
 			if -t2<T2-T1<t1:
 				ans=1-(	pow(T2-t1,2)+pow(T1-t2,2))/(2*prod)
 				print "%.6f" % ans
 			elif t1>T2:
 				if T2-T1+t2>0:
 					ans=1-(	pow(T1-t2,2)/(2*prod)	)
				else:
 					ans=0.5*T2*(2*t2+T2)/prod
 				print "%.6f" % ans
 			else:
 				if T2-T1+t2>0:
 					ans=1-(	(pow(T1-t2,2)+pow(T2-t1,2) )/(2*prod)	)
				else:
 					ans=(0.5*T2*(2*t2+T2)+0.5*pow(T2-t1,2))/prod
 				print "%.6f" % ans







 			

 
		
		t-=1
 
 
 
 
 
	exit(0)
if __name__=="__main__":
	main() 