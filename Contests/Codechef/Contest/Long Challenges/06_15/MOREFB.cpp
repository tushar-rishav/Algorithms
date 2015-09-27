#include <bits/stdc++.h>
#define FOR(i,j,k) for(int i=j;i<k;i++)
#define ll long long
#define ui unsigned int
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define MOD 99991
using namespace std;
map<ll, ll > d;
map<ll, ll>::iterator iter;

ll fib(ll n)
{
  ll a = 0, b = 1, c, i;
  if( n == 0)
    return a;
  for (i = 2; i <= n; i++)
  {

     c = a%MOD + b%MOD;
     a = b%MOD;
     b = c;

  }
  return b%MOD;
}


void subset(vector<ll> arr, ll size, ll left, ll index, list<ll> &l){
    if(left==0){
        ll sum=0;
        for(list<ll>::iterator it=l.begin(); it!=l.end() ; ++it){
            sum+=*it;
        }
        if(d.count(sum))
            d[sum]+=1;
        else
            d[sum]=1;
        return;
    }
    for(ll i=index; i<size;i++){
        l.push_back(arr[i]);
        subset(arr,size,left-1,i+1,l);
        l.pop_back();   
    }

}     

int main(){

    list<ll> lt;
    vector<ll> array;  
    ll f_sum=0,n,k,tmp;
    cin>>n>>k;
    FOR(i,0,n){
        cin>>tmp;
        array.push_back(tmp);
    }
    
    subset(array,n,k,0,lt);
    for(iter = d.begin(); iter != d.end(); iter++){
     f_sum+=( (((*iter).second)%MOD)*(fib((*iter).first)%MOD) )%MOD;
     if(f_sum>MOD)
        f_sum %=MOD;
    }
    cout<<f_sum;

    return 0;
}