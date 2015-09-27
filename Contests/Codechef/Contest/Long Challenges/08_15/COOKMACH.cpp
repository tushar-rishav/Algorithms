#include <bits/stdc++.h>
#define NDEBUG      // to suppress assertion error message
#define FORi(i,j,k) for(int i=j;i<k;i++)
#define FORll(i,j,k) for(long long i=j;i<k;i++)
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

#define ll long long
#define ull unsigned long long
#define db double
#define vci vector<int>
#define vcll vector<long long>
#define MOD 1000000007
using namespace std;

inline bool power2 (int x)
{
  return x && (!(x&(x-1)));
}
int main()
{  
	std::ios_base::sync_with_stdio(false);
	int t;
	ll a, b,move,v;
	
	cin>>t;
	while(t--){
		move=0;
		cin>>a>>b;
		v=a;
		while(true){
		if(power2(v)){
			if(v>b){
				while(v>>1>=b)
				{
					v=v>>1;
					move++;
				}
			}
			else{
				while(v<<1<=b){
					v=v<<1;
					move++;
				}

			}
			cout<<move<<endl;
			break;
		}

		if(v&1){
			v=(v-1)>>1;
			move++;
		}
		else{
			v=v>>1;
			move++;
		}

	}

}

	return 0;
}