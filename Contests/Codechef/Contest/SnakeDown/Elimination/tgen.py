from random import randint

if __name__=="__main__":
	d=str()
	l=50000
	
	for i in xrange(0,l):
		d+=chr(randint(97,122))
	print d+d[::-1]
	q=33
	print q
	while q:
		print randint(1,l),randint(1,l),randint(1,l),randint(1,l)
		q-=1
