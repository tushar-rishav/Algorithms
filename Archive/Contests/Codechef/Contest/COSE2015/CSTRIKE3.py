from sys import exit,stdin

if __name__ == "__main__":
	t = input()
	while t:
		r = raw_input().split()[0]
		if len(set(r)) & 1:
			print "Counter Terrorist"
		else:
			print "Terrorist"

		t-=1
	exit(0)