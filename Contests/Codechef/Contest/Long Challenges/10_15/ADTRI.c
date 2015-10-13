#include <stdio.h>
typedef long long ll;
typedef unsigned long long ull;
typedef double db;


# define rep(i, n) for((i) = 0; (i) < (n); (i)++)
# define repk(i,k,n) for( (i) = k; (i) < (n); (i)++)
# define REP(i, n) for( (i) = 1; (i) <= (n); (i)++)


# define MOD 1000000007

int hypo[5000004] = {0};

ll gcd(ll a, ll b){
	if(!a)
		return b;
	return gcd(b%a,a);
}

void triples(){
	ll u = 2237,c,k, N = 5000000,temp,m,n;
	repk(m,2,u){
		repk(n,1,m){
			if(gcd(m,n)==1){
				k = 1;
				c = m*m + n*n;
				while(1){
					temp = k*c;
					if(temp > N)
						break;
					hypo[temp]++;
					
					k++;
				}
			}
		}
	}
	
}

main(){  
	ll t,n;
	triples();
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		if(hypo[n])
			printf("YES\n");
		else
			printf("NO\n");

	}

	return 0;
}