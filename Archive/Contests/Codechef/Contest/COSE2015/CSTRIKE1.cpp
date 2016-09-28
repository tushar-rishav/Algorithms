#include <bits/stdc++.h>
# define NDEBUG
# define DEBUG(x) cout << '>' << #x << ':' << x << endl;
# define pll pair < ll, ll >
# define fs first 
# define se second
# define mp make_pair
# define pb push_back
# define rep(i, n) for( ll (i) = 0; (i) < (n); (i)++)
# define REP(i, n) for( ll (i) = 1; (i) <= (n); (i)++)
# define wl(i) while((i)--)
# define ma map < ll, ll >
# define sf(i) scanf("%lld",&(i))
# define pr(i) printf("%lld ",(i))
# define prn(i) printf("%lld\n",(i))
# define cpr(i) cout<<(i)<<" "
# define cprn(i) cout<<(i)<<endl
# define csf(i) cin>>(i)
# define srt(v) sort( v.begin(), v.end() )
# define srtc(v, x) sort( v.begin(), v.end(), x)
# define srtr(v) sort( v.begin(), v.end(), greater< ll >())
# define MAX_PRIME 0
# define SEGMENT_MAX 100005
# define ll long long
# define ull unsigned long long
# define db double
# define vci vector<int>
# define vcll vector<long long>
# define MOD 1000000007
using namespace std;

bool findPartiion (vci &arr, int n)
{
   int sum = 0;
    int i, j;
   
    for (i = 0; i < n; i++)
      sum += arr[i];
     
    if (sum%2 != 0)  
       return false;
   
    bool part[sum/2+1][n+1];
     
    for (i = 0; i <= n; i++)
      part[0][i] = true;
       
    for (i = 1; i <= sum/2; i++)
      part[i][0] = false;     
      
     for (i = 1; i <= sum/2; i++)  
     {
       for (j = 1; j <= n; j++)  
       {
         part[i][j] = part[i][j-1];
         if (i >= arr[j-1])
           part[i][j] = part[i][j] || part[i - arr[j-1]][j-1];
       }        
     }    
   
     return part[sum/2][n];
}   

int main()
{  
	std::ios_base::sync_with_stdio(false);
	int t,n,i,temp,n_c;
	vci arr;
	cin>>t;
	while(t--){
		cin>>n;
		n_c=n;
		i=0;
		while(n--){
			cin>>temp;
			arr.pb(temp);
		}
	if (findPartiion(arr, n_c) == true)
		cout<<"YES"<<endl;
	
	else
		cout<<"NO"<<endl;
	arr.clear();
	}

	
	return 0;
}