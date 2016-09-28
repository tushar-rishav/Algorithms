/*
	Find the GCD of two given numbers with recursive approach.
	NOTE: gcd(a,b) = gcd(b%a, a)
	lcm(a,b) = (a*b)/gcd(a,b);
*/
#include <bits/stdc++.h>
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define ll long long
#define MOD 1000000007
using namespace std;

ll egcd(ll a, ll b){ // Euclid GCD Algo
	if(!a)
		return b;
	return gcd(b%a,a);
}
ll bgcd(ll x,ll y)		// Binary GCD Algo
    {
    x=abs(int(x));
    y=abs(int(y));
    ll z; int x0,y0,sh=0;
    for (;;){
        if (!x){
        	z=y; break;
        }
        if(!y){
        	z=x; break;
        }
        x0=x&1 ;
        y0=y&1 ;
        if ((!x0)&&(!y0)){
        	x>>=1; y>>=1; sh++; continue;
        }
        if (!x0){
        	x>>=1; continue; 
        }
        if (!y0){
        	y>>=1; continue;
        }
        if (x<y)
        	y-=x;
        else
        	x-=y;
    }
    return (z<<sh);
}

int main(){  
	std::ios_base::sync_with_stdio(false);
	ll a,b;
	cin>>a>>b;
	cout<<egcd(a,b);
	cout<<bgcd(a,b);
	return 0;
}