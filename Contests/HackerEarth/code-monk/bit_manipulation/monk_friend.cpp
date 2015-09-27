#include <bits/stdc++.h>
# define vci vector<int>
using namespace std;
inline long long count1(long long n){
	long long count = 0;
	while(n){
	n = n & (n-1);
	count++;
	}
	return count;

}
int main(){

std::ios_base::sync_with_stdio(false);
long long t,p,m,bit;


cin>>t;
while(t--){
	cin>>p>>m;
	bit = p^m;
	cout<<count1(bit)<<endl;
}
return 0;
}
