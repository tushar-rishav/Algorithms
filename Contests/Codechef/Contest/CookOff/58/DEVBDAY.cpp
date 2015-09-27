#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define ll long long
#define ui unsigned int
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

using namespace std;
int main(){

	std::ios_base::sync_with_stdio(false);
	
	int t,n;
	ll inp;

	deque<ll> f;
	deque<ll> r;
	cin>>t;
	while(t--){
		cin>>n;
		FOR(i,0,n-1){
			cin>>inp;
			f.push_back(inp);
		}
		FOR(i,0,n-1){
			cin>>inp;
			r.push_back(inp);
		}
		ll repeat=0,max_amt=0;
			
		FOR(i,0,n-1){
			if (r[f[i]-1]+r[i]>0){
				if (f[f[i]-1]!=(i+1))
					max_amt+=(r[f[i]-1]+r[i]);
					//DEBUG(max_amt);

				else
					repeat+=r[f[i]-1]+r[i];
			}	
				
		}		
		max_amt+=(repeat/2);		
		cout<<max_amt<<"\n";
		f.clear();
		r.clear();	



		}





	return 0;
}