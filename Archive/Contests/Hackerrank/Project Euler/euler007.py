from math import sqrt,pow
from collections import deque,Counter
import time

def main():
	t=input()
	while t:
		start = time.time()
		n=int(raw_input())
		arr_sq=deque(i*i for i in xrange(1,n+1))
		arr=deque(xrange(1,n+1))
		i=n-1
		max_py=-1
		while i>1:
			j=0
			k=i-1
			while j<k:
				if arr_sq[j]+arr_sq[k]>arr_sq[i]:
					k-=1
				elif arr_sq[j]+arr_sq[k]<arr_sq[i]:
					j+=1
				else:
					if arr[j]+arr[k]+arr[i]==n:
						if arr[j]*arr[k]*arr[i]>max_py:
							max_py=arr[j]*arr[k]*arr[i]
					k-=1
					j+=1
			elapsed = time.time() - start
			if elapsed>10:
				print "Time taken %f was GREATER THAN 10" %elapsed
				exit(1)
			i-=1

		if max_py>0:
			print max_py
		else:
			print -1
		elapsed = time.time() - start
		print "Time taken was %f" %elapsed

		


		t-=1


if __name__=="__main__":
	main()