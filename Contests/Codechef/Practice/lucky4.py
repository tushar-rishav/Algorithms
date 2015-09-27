#! /usr/bin/env python
from math import factorial


def main():
    t=input()
    while t:
    	n=raw_input()
    	#indices = [i for i, x in enumerate(n) if x == "4"]
    	print n.count("4")
    	t-=1

if __name__=="__main__":
    main()
