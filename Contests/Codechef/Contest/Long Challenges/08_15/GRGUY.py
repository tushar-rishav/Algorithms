from sys import stdin,exit

if __name__ == "__main__":
	t=map(int,stdin.readline().split())[0]
	while t:
		l1 = raw_input().split()[0]
		l2 = raw_input().split()[0]
		l1_dot = l1.count('.')
		l2_dot = l2.count('.') 
		brk=False
		l = len(l1)
		if l1[-1] == l2[-1] =="#":
			print "No"
			t-=1
			continue
		if l1[0]!="#" or l2[0]!="#":	
			if l1_dot > l2_dot:
				if l1[0]!="#":
					cl=l1	# current lane
					al=l2	# adjacent lane
				else:
					cl=l2
					al=l1
			else:
				if l2[0]!="#":
					cl=l2	# current lane
					al=l1	# adjacent lane
				else:
					cl=l1
					al=l2
			#print cl,al
			i=0
			j=0
			g_jump = 0
			while j<l-1:
				if cl[j+1] == "#" and al[j+1] ==".":
					g_jump+=1
					cl, al = al, cl

				elif cl[j+1] == al[j+1] == "#":
					print "No"
					brk = True
					break
				
				j+=1
		else:
			print "No"
			brk=True
			break
		
		if not brk:
			print "Yes"
			print g_jump
		
		t-=1