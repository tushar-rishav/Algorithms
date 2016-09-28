from sys import stdin,exit

def main():
	T = int(input())
	cs = set()
	slope_to_c = {}
	perp = set()
	slope = 0
	cons = 0
	while T:
		N = int(input())
		NC = N
		while NC:
			A, B, C = map(float, stdin.readline().split())
			if N>1:
				if(B):
					slope = A/B
					cons = C/B
					if( slope_to_c.has_key(slope)):
						slope_to_c[slope].add(cons)
					else:
						cs = set()
						cs.add(cons);
						slope_to_c[slope] = cs
				else:
					perp.add(C/A)

			NC -= 1

		if N>1:
			m = 0
			cm = 0
			for it in slope_to_c.values():
				cm = len(it)
				if(cm > m):
					m = cm
			m = 1 if max(m,len(perp))==1 else max(m,len(perp))
			print m
			slope_to_c = {};
			perp.clear();
			cs.clear();
		else:
			print 1

		T -= 1
	exit(0)

if __name__ == "__main__":
	main()