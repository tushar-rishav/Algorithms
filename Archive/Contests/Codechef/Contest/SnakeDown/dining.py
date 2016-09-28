from sys import *

def main():
	t=map(int, raw_input().split())
	while t[0]:
		try:
			inp=list()
			n,d,k=map(int, raw_input().split())
			# read the input
			for i in range(n):
				f=map(float,stdin.readline().split())
				inp.append(f)
			prob=1
			poss=list()
			trans=zip(*inp)	# take a transpose
			for i in range(len(trans)):
				trans[i]=list(trans[i])
			for i in range(d):
				m_dish=max(trans[i])
				m_pos_dish=trans[i].index(m_dish)+1  # 1 indexing
				
				if not (m_pos_dish in poss):
					poss.append(m_pos_dish)
					prob*=m_dish
					for i in range(n):
						trans[i][m_pos_dish-1]=-1.0


			print prob
			for i in poss:
				print i,
			print	
		except:
			pass	
			
		t[0]-=1


	exit(0)	



if __name__=="__main__":
	main()	