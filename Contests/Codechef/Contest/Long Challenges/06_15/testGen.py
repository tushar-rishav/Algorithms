from random import randint
from sys import exit
def main():
	n=20
	k=20
	print n,k
	u_l=int(pow(10,7))
	while n:
		print randint(1,u_l),

		n-=1
	exit(0)
if __name__=="__main__":
	main()
