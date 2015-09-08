/*
	Find the GCD of two given numbers.
	NOTE: gcd(a,b) = gcd(b%a, a)
*/
#include <bits/stdc++.h>
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
#define MOD 1000000007
using namespace std;

ll gcd(ll a, ll b){
	if(!a)
		return b;
	return gcd(b%a,a);
}

int main(){  
	std::ios_base::sync_with_stdio(false);
	ll a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}