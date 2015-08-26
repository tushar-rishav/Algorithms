/*
	Find Nth Magic number

*/
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

ll nthmagic(int n){
	
	ll p = 1,sm = 0;
	p*=5;
	while(n){
		if(n&1)
			sm+=p;
		p*=5;
		n>>=1;	// right shift by 1
	}
	return sm;
}

int main()
{  
	std::ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	cout<<nthmagic(n)<<endl;
	return 0;
}
