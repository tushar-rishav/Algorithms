def main():
	n=input()
	gem=[]
	while n:
		gem.append(set(raw_input()))
		n-=1
	intersect=gem[0]
	for i in gem:
		intersect=intersect&i
	print len(intersect)

if __name__=="__main__":
	main()

