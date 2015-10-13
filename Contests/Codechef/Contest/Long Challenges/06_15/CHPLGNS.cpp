#include <bits/stdc++.h>
#define FOR(i,j,k,s) for(int i=j;i<k;i+=s)
#define ll long long
#define ui unsigned int
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
using namespace std;
int main(){
 
	std::ios_base::sync_with_stdio(false);
	
	vector<ll> p_x,p_y,p_area;
	vector<ll>::iterator it;
	ll n,t,l,m,e,a,area=0,id,pas;
	string line;
	cin>>t;
	while(t){
		cin>>n;
		while(n){
			cin>>m;
			ll x,y;
			for(ll i=0;i<m;i++)
			{
				cin>>x>>y;
				p_x.push_back(x);
				p_y.push_back(y);
			}
			p_x.push_back(p_x[0]);
			p_y.push_back(p_y[0]);
			if(m%2){
				p_y.push_back(p_y[0]);
				p_x.push_back(p_x[0]);
			}
			area = 0;
			FOR(i,0,m,2)
	   			area += p_x[i+1]*(p_y[i+2]-p_y[i]) + p_y[i+1]*(p_x[i]-p_x[i+2]);
			area = abs(area/2);
			
			//DEBUG(area)
			p_area.push_back(area);
			p_x.clear();
			p_y.clear();
			n--;
		}
			vector<ll> cpy(p_area);
			sort(cpy.begin(),cpy.end());
			pas=p_area.size();
			FOR(i,0,pas,1){
			 	it=find(cpy.begin(), cpy.end(),p_area[i]);
			   	if (it != cpy.end())
			   		cout<<distance(cpy.begin(), it)<<" ";
			 		
			   }
			cout<<endl;
			cpy.clear();
			p_area.clear();
		t--;
	}
	return 0;
} 