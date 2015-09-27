#include <bits/stdc++.h>
#define NDEBUG
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

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

#define ll long long
#define ull unsigned long long
#define db double
#define vci vector<int>
#define vcll vector<long long>
#define MOD 1000000007
using namespace std;

inline ll fast_exp(int base, int exp) {
    ll res=1;
    while(exp>0) {
       if(exp&1)
       		res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp>>=2;
    }
    return res%MOD;
}

int main()
{  
	std::ios_base::sync_with_stdio(false);
	int t;
	ll n,sm=0;
	cin>>t;

	while(t--){
		cin>>n;

		REP(i,n){
			if((n-i)&1){
				sm = ((sm % MOD) + fast_exp(2,1+ (n-i)>>1)%MOD)%MOD;
			}
			else if(n-i){
				sm = ((sm % MOD) + fast_exp(2,(n-i)>>1)%MOD)%MOD;
			}
			else
				sm = (sm%MOD + 2)%MOD;

		}
		cout<<sm<<endl;
		sm = 0;
	}

	return 0;
}