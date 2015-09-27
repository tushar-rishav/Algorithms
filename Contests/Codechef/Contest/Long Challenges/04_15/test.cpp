#include<cstdio>
#define MOD 1000000009
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll gcd(ll a,ll b)
{
    ll t;
    while(b)
    {
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

void div_by_gcd(ll &a, ll &b)
{
    ll g=gcd(a,b);
    a/=g;
    b/=g;
}

ll C(int n,int k)
{
    ll num=1,den=1,toMul,toDiv;
    if(k>n/2) k=n-k;
    for(int i=k;i>0;i--)
    {
        toMul=n-k+i;
        toDiv=i;
        div_by_gcd(toMul,toDiv);
        div_by_gcd(num,toDiv);
        div_by_gcd(toMul,den);
        num*=toMul;
        den*=toDiv;
    }
    return num/den;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%lld\n",(n*C(2*n,n))/2);
    }
}
