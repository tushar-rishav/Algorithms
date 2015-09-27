def prnt(l):
	for i in l:
		print i,
	print
	

def subset(arr,size,left, index,l):
	if(left==0):
		prnt(l)
		return
	
	for i in xrange(index,size):
		l.append(arr[i])
		subset(arr,size,left-1,i+1,l)
		l.pop()   

def main():
	array=[1,2,3,4,5]
	lt=list()   
	size=2
	arrzy_size=5
	subset(array,array_size,size,0,lt)

if __name__=="__main__":
	main()