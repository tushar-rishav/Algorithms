#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

# define fs first 
# define se second
# define bg begin
# define rbg rbegin
# define en end
# define ren rend
# define mp make_pair
# define pub push_back
# define pob pop_back
# define cl clear
# define em empty
# define fe for_each
# define np next_permutation
# define pp prev_permutation

# define DEBUG(x) cout << '>' << #x << ':' << x << endl;
# define all(c) c.bg(), c.en()
# define rall(c) c.rbg(), c.ren()

# define pll pair < ll, ll >
# define pllit pair < ll, ll >::iterator
# define mll map < ll, ll >
# define mllit map < ll, ll >::iterator
# define msl map < string, ll >
# define mslit map < string, ll >::iterator
# define vll vector< ll >
# define vvll vector< vll >
# define vllit vector< ll >::iterator
# define vc vector<char>
# define vcit vector<char>::iterator
# define sll set< ll >
# define sllit set< ll >::iterator

# define srt(v) sort( v.bg(), v.en() )
# define srtr(v) sort( v.rbg(), v.ren())
# define srtc(v, x) sort( v.bg(), v.en(), x)
# define tr(container, it) for(typeof(container.bg()) it = container.bg(); it != container.en(); it++)
# define rtr(container, it) for(typeof(container.rbg()) it = container.rbg(); it != container.ren(); it++) 
# define present(container, element) (container.find(element) != container.en()) // O(logN) : use in case of Set and Maps
# define cpresent(container, element) (find(all(container),element) != container.en()) // global find(): for Vectors. O(N) 


# define rep(i, n) for( ll (i) = 0; (i) < (n); (i)++)
# define repk(i,k,n) for( ll (i) = k; (i) < (n); (i)++)
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

inline void Scan_f(long long *a)
{
	char c = 0;
	while(c<33)
		c = fgetc_unlocked(stdin);
	*a = 0;
	while(c>33){
		*a = (*a)*10 + c - '0';
		c = fgetc_unlocked(stdin);
	}
}

int main()
{  
	sync_false;
	ll t, n1,n1c,n2,n2c,m, k,s;

	Scan_f(&t);

	wl(t){
		s = 0;
		scanf("%lld %lld %lld",&n1, &n2, &m); 
		n1c = min(n1,n2);
		n2c = max(n1,n2);
		n1 = n1c; n2 = n2c;
		
		if (n1<=m){
			n2 -= n1; n1 = 0;
		}else{
			
			if ((2*m-1)*(2*m-1)-8*(n1-m) >= 0)
				k = floor((float)((2*m-1) - sqrt( (2*m-1)*(2*m-1)-8*(n1-m) ))/2);
			else
				k = m;
			//DEBUG(k)
			s = (k+1)*m - k*(k+1)/2;
			if((n1-s) && k < m)
			{
				n2 = n2 - n1;
				n1 = 0;
			}
			else{
				n2 = n1 + n2 - 2*s;
				n1 = 0;
			}

		}
			
		
		printf("%lld\n", n1+n2);
	}
	return 0;
}