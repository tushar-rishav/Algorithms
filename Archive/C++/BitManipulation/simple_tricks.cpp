/*
	generate all the possible subsets of a set
*/
	
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main(){
	
	vector<string> v;
	// x ^ ( x & (x-1)) : Returns the rightmost 1 in binary representation of x.
	v.pb("1]. x ^ ( x & (x-1)) : Returns the rightmost 1 in binary representation of x");
	//  x & (-x) : Returns the rightmost 1 in binary representation of x
	v.pb("2]. x & (-x) : Returns the rightmost 1 in binary representation of x");
	//x | (1 << n) : Returns the number x with the nth bit set
	v.pb("3]. x | (1 << n) : Returns the number x with the nth bit set");
	/*
			One can initialize a set from a vector:

			set<int> b(a.begin(),a.end()); // a is a vector<int>

			Going the other way is also possible:

			vector<int> c(b.begin(),b.end()); // b is a set<int>
			Doing these two operations after each other effectively sorts a vector of integers and removes all duplicate elements!

	*/
	for(int i =0;i<v.size();++i)
		cout<<v[i]<<endl;

	return 0;
}