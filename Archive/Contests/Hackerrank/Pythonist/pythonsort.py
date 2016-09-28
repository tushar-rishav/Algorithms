from sys import stdin
def main():
	n,m=map(int,stdin.readline().split())
	table=[]
	while n:
		table.append(tuple(map(int,stdin.readline().split())) )
		n-=1
	k=input()
	table=sorted(table,key=lambda row: row[k])
	for i in table:
		for j in i:
			print j,
		print


if __name__=="__main__":
	main()