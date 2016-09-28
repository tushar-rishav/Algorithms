#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=j;i<k;i+=1)
#define ll long long
#define ui unsigned int
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define vc vector<long long>

using namespace std;
inline int read()
{
	int ret = 0;
	int c = getchar_unlocked();
 
	while(c<'0' || c>'9')
		c = getchar_unlocked();
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret;
}

int main(){
 
	std::ios_base::sync_with_stdio(false);
	
	ll n,q,x,y,t;
	ll result;
	vc list;
	n=read();
	q=read();
	FOR(i,0,n){
		cin>>t;
		list.push_back(t);
	}
	while(q--){
		cin>>x>>y;
		 result= *max(list.begin()+x,list.begin()+y)-*min(list.begin()+x,list.begin()+y);
		 cout<< result;
		//cout<<*(list.begin()+x)<<","<<*(list.begin()+y);
		cout<<"\n";	



	}
	return 0;
}