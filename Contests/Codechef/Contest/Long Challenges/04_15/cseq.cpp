#include<stdio.h>
#include <iostream>
#include <math.h>
#define MOD 1000003
using namespace std;
 
long long C(long long n, long long r)
{
    if (r==0) return 1;
    else 
    	return C(n-1,r-1) * n / r;
}

long long n,l,r,m=1,sm=0,p,c,s,a,b;
 
int main()
{
    std::ios_base::sync_with_stdio(false);
    int t;
    
    cin>>t;
    while(t--){
    sm=0;
    cin>>n;
    cin>>l;
    cin>>r;
    p=r-l+1;
    
  	sm=(C(n+p,n)%MOD-1%MOD)%MOD;
  
    cout<<sm<<endl;
    
    }
    
    return 0;
}
