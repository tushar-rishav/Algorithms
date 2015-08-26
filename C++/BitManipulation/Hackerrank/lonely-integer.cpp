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
int main()
{  
	std::ios_base::sync_with_stdio(false);
	int n,t_prev,t_next;
	cin>>n;
	cin>>t_prev;
	while(n>1){
		cin>>t_next;
		t_prev = t_prev ^ t_next;
		n-=1;
	}
	cout<<t_prev<<endl;
	return 0;
}