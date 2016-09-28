from sys import stdin,exit
 
def main():
	t=int(raw_input())
	while t:
		words=map(str,stdin.readline().split())
		tpClr=words[-2]
		btmClr=words[-1]
		r1=words[:2]
		r2=words[2:4]
		if tpClr in r1 and tpClr in r2:
			print "YES"
		elif btmClr in r1 and btmClr in r2:
			print "YES"
		else:
			print "NO"
 
		t-=1
	exit(0)
 
 
if __name__=="__main__":
	main()