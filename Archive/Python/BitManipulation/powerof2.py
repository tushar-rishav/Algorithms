def power2(x):
	"""
		Method to check if x is power of 2
	"""
	return x and (not(x&(x-1)))

def even(x):
	"""
		return 1 if x is even else return 0
	"""
	return not(x&1)
	
