/*
	Find Nth Magic number

*/
#include <bits/stdc++.h>

# define DEBUG(x) cout << '>' << #x << ':' << x << endl;

# define ll long long
# define ull unsigned long long
# define db double

# define pll pair < ll, ll >
# define pllit pair < ll, ll >::iterator
# define mll map < ll, ll >
# define mllit map < ll, ll >::iterator
# define msl map < string, ll >
# define mslit map < string, ll >::iterator
# define vll vector< ll >
# define vllit vector< ll >::iterator
# define sll set< ll >
# define sllit set< ll >::iterator

# define fs first 
# define se second
# define bg begin
# define en end
# define mp make_pair
# define pub push_back
# define pob pop_back
# define cl clear
# define em empty
# define fe for_each

# define srt(v) sort( v.begin(), v.end() )
# define srtc(v, x) sort( v.begin(), v.end(), x)
# define srtr(v) sort( v.begin(), v.end(), greater< ll >())

# define rep(i, n) for( ll (i) = 0; (i) < (n); (i)++)
# define REP(i, n) for( ll (i) = 1; (i) <= (n); (i)++)
# define wl(i) while((i)--)
# define sf(i) scanf("%lld",&(i))
# define pf(i) printf("%lld ",(i))
# define pfn(i) printf("%lld\n",(i))
# define csf(i) cin>>(i)
# define cpf(i) cout<<(i)<<" "
# define cpfn(i) cout<<(i)<<endl


# define MAX_PRIME 0
# define SEGMENT_MAX 100005
# define MOD 1000000007
# define sync_false std::ios_base::sync_with_stdio(false)
	
const unsigned char option1 = 0x01; // hex for 0000 0001
const unsigned char option2 = 0x02; // hex for 0000 0010
const unsigned char option3 = 0x04; // hex for 0000 0100
const unsigned char option4 = 0x08; // hex for 0000 1000
const unsigned char option5 = 0x10; // hex for 0001 0000
const unsigned char option6 = 0x20; // hex for 0010 0000
const unsigned char option7 = 0x40; // hex for 0100 0000
const unsigned char option8 = 0x80; // hex for 1000 0000
using namespace std;

ll nthmagic(int n){
	
	ll p = 1,sm = 0;
	p*=5;
	wl(n){
		if(n&1)
			sm+=p;
		p*=5;
		n>>=1;	// right shift by 1
	}
	return sm;
}

int main(){
  
	sync_false;
	ll n;
	csf(n);
	cpfn(nthmagic(n));
	return 0;
}