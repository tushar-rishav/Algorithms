def prime(n,a):
	i = a
	while (n%i != 0 and i*i < n):
		i += 1
	if (i*i < n):
		return prime (n/i, i)
	else:
		print n
if __name__=="__main__":
	t=input()
	while t:
		n=input()
		prime(n,2)
		t-=1