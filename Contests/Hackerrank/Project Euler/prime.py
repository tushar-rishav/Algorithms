from time import time
def is_prime(n):
	if n <= 3:
		return n >= 2
	if n % 2 == 0 or n % 3 == 0:
		return False
	for i in xrange(5, int(n ** 0.5) + 1, 6):
		if n % i == 0 or n % (i + 2) == 0:
			return False
	return True
if __name__=="__main__":
	n=input()
	start=time()
	print is_prime(n)
	print time()-start
