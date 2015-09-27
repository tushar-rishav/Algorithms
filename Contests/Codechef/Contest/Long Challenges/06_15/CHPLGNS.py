from sys import exit,stdin
from copy import copy
def area(N,x,y):
	area = 0
	for i in xrange(0,N,2):
	   area += x[i+1]*(y[i+2]-y[i]) + y[i+1]*(x[i]-x[i+2])
	area /= 2
	return area

def main():
	t=input()
	while t:
 
		poly_x=[]	# store X coord
		n=int(raw_input())		# no of polygons
		#l=n
		while n:
			m=int(raw_input())		# M Pairs
			poly=map(int,stdin.readline().split())
			poly.append(poly[0])
			poly.append(poly[1])
			if m%2:
				poly.append(poly[0])
				poly.append(poly[1])

			poly_x.append( abs(area(m,poly[::2],poly[1::2])) )
			n-=1
		cpy=sorted(poly_x)
		for i in poly_x:
			print cpy.index(i),
		print
		
 
		
		t-=1
 
 
 
 
 
	exit(0)
if __name__=="__main__":
	main() 