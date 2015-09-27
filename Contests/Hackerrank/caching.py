from sys import stdin
def main():
	n=input()
	n_l=map(int,stdin.readline().split())
	m=input()
	m_l=map(int,stdin.readline().split())
	n_l.sort()
	m_l.sort()
	n_dict={}
	m_dict={}
	i=0
	while i<n:
		if n_dict.has_key(n_l[i]):
			n_dict[n_l[i]]+=1
		else:
			n_dict[n_l[i]]=1
		i+=1
	i=0
	while i<m:
		if m_dict.has_key(m_l[i]):
			m_dict[m_l[i]]+=1
		else:
			m_dict[m_l[i]]=1
		i+=1
	miss=[]
	for key,value in n_dict.iteritems():
		if m_dict.has_key(key):
			if not(m_dict[key]==value):
				miss.append(key)
		else:
			miss.append(key)
	miss.sort()
	for i in miss:
		print i,y



if __name__=="__main__":
	main()
	