#include<bits/stdc++.h>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define ll long long
#define ui unsigned int
#define MOD 1000000007
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

using namespace std;
int main(){
	std::ios_base::sync_with_stdio(false);

	deque<int> A;
	ll n,miny,maxy,inp;
	int t;

	cin>>t;
	while(t--){
		cin>>n;
		FOR(i,0,n-1){
			cin>>inp;
			A.push_back(inp);
		}
		if(n%2)
			maxy=(n+1)/2;
		else
			maxy=n/2;
		if(n%3)
			miny=(n/3)+1;
		else
			miny=n/3;
		printf("%lld %lld\n",miny,maxy);


	}
	return 0;

}