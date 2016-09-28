from sys import stdin,exit

def main():
	n=int(raw_input())
	p=n
	M={}
	while p:
		Pin,D,S=map(str,stdin.readline().split())

		
		if S[1]=='1':
			print "drop"
		else:
			if M.has_key(S):
				if M[S]!=Pin:
					M[S]=Pin
			else:
				M[S]=Pin
			if D[1]=='1':
				print "flood"
			elif not M.has_key(D):
				print "flood"
				
			else:
				Pout=M[D]
				if Pin==Pout:
					print "drop"
				else:
					print Pout

			
		p-=1





if __name__=="__main__":
	main()