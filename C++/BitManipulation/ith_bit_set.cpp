/*
	Check if the ith bit is set in the binary form of the given number.
*/
#include <bits/stdc++.h>
using namespace std;
bool is_ith_bit_set(int n,int i){
	return n & (1<<i);
}

int main(){
cout<<is_ith_bit_set(20,2);
return 0;
}
