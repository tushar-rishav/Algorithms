#include<bits/stdc++.h>
#define FOR(i,j,k,step) for(int i=j;i<=k;i+=step)
#define ll long long
#define gc getchar_unlocked
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
 
using namespace std;
vector<ll>pf;
ll gcd(ll a,ll b) {
  if (b == 0) {
    return a;
  }
  else {
    return gcd(b, a % b);
  }
}
inline void primeFactors(ll n,ll a)
{
	ll sq;
	while (n%2 == 0)		//O(log(n))
    {
        pf.push_back(n);	
        n = n/2;
    }
    sq=sqrt(n);
    for (int i = 3; i <= sq; i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
			pf.push_back(n);
            n = n/i;
        }
    }
 
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2){
        
        	pf.push_back(n);
        	}
       FOR(i,1,pf.size()-1,1){
       	//cout<<pf[i]<<",";
       	if(a%pf[i])
       		{cout<<"No"<<endl; pf.clear();
       		return;}
       }
       cout<<"Yes"<<endl; 	
       pf.clear();
       return;
}
 
 
int main(){
	std::ios_base::sync_with_stdio(false);
	ll a,b,t,h,c;
	cin>>t;
	while(t--){
	cin>>a>>b;
	h=gcd(a, b);
	primeFactors(b,h);
	/*h=gcd(a, b);
	
	if(h!=1)
		primeFactors(b,h);
	else if(h==1 && b>1)
		cout<<"No"<<endl;
	if(b==1)
		cout<<"Yes"<<endl;
	
	/*while(1){
		
		h=gcd(a,b);
		c=b/h;
		if(c==1)
			{cout<<"Yes"<<endl;break;}
		h=gcd(a,c);
		if(h==1)
			{cout<<"No"<<endl;break;}
	}*/
	}
 
 
return 0;
}
 
