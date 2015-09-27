from random import randint
from sys import exit
def main():
	n=20
	k=20
	big=10**6
	print n,k
	for i in xrange(n):
		print randint(1,big),
	print

	exit(0)
if __name__=="__main__":
	main()
