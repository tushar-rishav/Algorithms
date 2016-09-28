/*
	Computing a**n with log(n) time complexity
	NOTE: (ABC)% P = ((((A%P)*(B%P))%P) * (C%P))%P 
*/
#include <bits/stdc++.h>
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
#define MOD 1000000007
using namespace std;

ll expo(ll a,ll n){
	if(!n)
		return 1;
	if(n == 1)
		return a;
	ll e = expo(a,n/2)%MOD;
	return (n & 1)? (((a%MOD*e%MOD)%MOD)*e%MOD)%MOD :(e%MOD*e%MOD)%MOD;
	
}	

int main(){  

	std::ios_base::sync_with_stdio(false);
	ll a,n;
	cin>>a>>n;
	cout<<expo(a,n)<<endl;
	return 0;
}