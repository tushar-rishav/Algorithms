#include<bits/stdc++.h>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define ll long long
#define ui unsigned int
#define MOD 1000000007

inline ll power(ll x, ui y)
{
    ll temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}

using namespace std;

int main(){

	std::ios_base::sync_with_stdio(false);
	ll t,n,inp;
	ll sm,sz;
	string str;
    string buf;
    
	deque<int>Ma;
	cin>>t;
	while(t--){
	
		sm=0;
		cin>>n;
		FOR(i,0,n-1){
			cin>>inp;
			Ma.push_back(inp);
		}			
		sz=Ma.size();
		FOR(i,0,sz-1)
			sm+=( (Ma[i]-Ma[sz-i-1]) * (power(2,sz-i-1)-1) )%MOD;
			
		cout<<abs(sm)<<endl;
		Ma.clear();
		
	}

	return 0;
}
