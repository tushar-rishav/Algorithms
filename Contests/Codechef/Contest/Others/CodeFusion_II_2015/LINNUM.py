from sys import stdin,exit
t = int(raw_input().split()[0])
while t:
	n = int(raw_input().split()[0])
	a = map(str,stdin.readline().split())
	x = raw_input().split()[0]
	max_count_num = a[0]
	max_count = a[0].count(x)
	for i in a:
		cnt = i.count(x)
		if cnt > max_count:
			max_count_num = i
			max_count = cnt
	print max_count_num

	t-=1