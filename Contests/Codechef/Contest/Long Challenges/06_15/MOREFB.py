from sys import exit,stdin
from collections import Counter
from time import time

class MatrixFibonacci:
	Q = [[1, 1],
		 [1, 0]]

	def __init__(self):
		self.__memo = {}

	def __multiply_matrices(self, M1, M2):
		a11 = M1[0][0]*M2[0][0] + M1[0][1]*M2[1][0]
		a12 = M1[0][0]*M2[0][1] + M1[0][1]*M2[1][1]
		a21 = M1[1][0]*M2[0][0] + M1[1][1]*M2[1][0]
		a22 = M1[1][0]*M2[0][1] + M1[1][1]*M2[1][1]
		r = [[a11, a12], [a21, a22]]
		return r

	def __get_matrix_power(self, M, p):
		
		if p == 1:
			return M
		if p in self.__memo:
			return self.__memo[p]
		K = self.__get_matrix_power(M, int(p/2))
		R = self.__multiply_matrices(K, K)
		self.__memo[p] = R
		return R

	def get_number(self, n):
		if n == 0:
			return 0
		if n == 1:
			return 1
		powers = [int(pow(2, b))
				  for (b, d) in enumerate(reversed(bin(n-1)[2:])) if d == '1']
		matrices = [self.__get_matrix_power(MatrixFibonacci.Q, p)
					for p in powers]
		while len(matrices) > 1:
			M1 = matrices.pop()
			M2 = matrices.pop()
			R = self.__multiply_matrices(M1, M2)
			matrices.append(R)
		return matrices[0][0][0]
def subset(arr,size,left, index,l):
	if(left==0):
		d[sum(l)]+=1
		return
	
	for i in xrange(index,size):
		l.append(arr[i])
		subset(arr,size,left-1,i+1,l)
		l.pop() 
d=Counter()
def main():
	MOD=99991
	f_sum=0
	mfib =MatrixFibonacci()
	n,k=map(int,stdin.readline().split())
	st=map(int,stdin.readline().split())
	#start=time()
	lt=list()   
	subset(st,n,k,0,lt)

	for i in d:
		f_sum=(f_sum+d[i]*mfib.get_number(i))

	
	print f_sum%MOD
	#print time()-start
	exit(0)


if __name__=="__main__":
	main()


