#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
#define mod 1000000007

using namespace std;
typedef long long ll; 
ll power(ll b,ll ex){
	ll r_m,rm,rs;
	if(!ex)
		return 1;
	r_m = 1;
	rs = b;
	while(ex > 1){
		rm=ex % 2;
		if (rm > 0)
			r_m = r_m * rs;
		ex = (ex - rm) / 2;
		rs = rs * rs;
	}
	return rs * r_m;
	
	}
ll gcd(ll i,ll n){
	for(ll j=2;j<i+1;j++ ){
		if ( !(i%j) && !(n%j))
			return j;
	}		
	return 1;
	}		 

int main()
{
	ios_base::sync_with_stdio(false);
	
	ll t,g,n,k,su=0;
	cin>>t;

	
	while(t--){
		cin>>n>>k;
		su+=1;
		if (!(n%2)){
			for(ll i=3;i<n;i+=2){
				g=gcd(i,n);
				if(g==1)
					su+=(power(i,k)%mod);
			}
		}		
		else{	
			for (ll i=2;i<n;i++){
				g=gcd(i,n);
				if(g==1)
					su+=(power(i,k)%mod);
			}
		}
		cout<<su<<endl;
		su=0;		
	}	
		
		
		
		
	
	
	
	
	return 0;
}
