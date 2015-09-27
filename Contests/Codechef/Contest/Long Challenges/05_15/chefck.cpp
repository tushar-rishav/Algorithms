#include<bits/stdc++.h>
#define FOR(i,j,k) for(int i=j;i<=k;i++)
#define ll long long

using namespace std;
inline ll miny(ll a,ll b)
{
    if( a < b)
        return a;
    else
        return b;
}
inline int fastread (){
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar_unlocked();
	while (true)
	{
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar_unlocked();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar_unlocked();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
inline int power(int x, unsigned int y)
{
    int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return temp*temp;
    else
        return x*temp*temp;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
	
	const int MOD=power(10,9)+7;
	//vector<ll> Ar;
	deque<ll> Ar;
	ll n,k,q,a, b, c, d, e, f, r, s, t, m,a1,L1, La, Lc, Lm, D1, Da, Dc,Dm,Lf,Rt,ps;
	cin>>n>>k>>q;
	cin>>a>>b>>c>>d>>e>>f>>r>>s>>t>>m>>a1;
	//L1=fastread();La=fastread();Lc=fastread();Lm=fastread();D1=fastread();Da=fastread();Dc=fastread();Dm=fastread();
	cin>>L1>>La>>Lc>>Lm>>D1>>Da>>Dc>>Dm;
	
	Ar.push_back(0);
	Ar.push_back(a1);		// Ar[1]
	
	FOR(x,2,n){
	ps=power(Ar[x-1],2);
	if((power(t,x)%s)<=r)
		Ar.insert(Ar.begin()+x, (ll)((a*ps + b*Ar[x-1] + c) % m));
	else
		Ar.insert(Ar.begin()+x, (ll)((d*ps + e*Ar[x-1] + f) % m));	
	}
	
	/*FOR(i,1,Ar.size()-1)
		cout<<Ar[i]<<",";
	cout<<endl;
		*/
	ll mEl,sm=0,iPd=1,pd;
	FOR(i,1,q){
		L1 = ( ((La*L1)%Lm ) +(Lc%Lm) ) % Lm;
		D1 = ((Da*D1)%Dm+ (Dc%Dm)) % Dm; 
		Lf = L1 + 1;
		Rt = miny(Lf + k - 1 + D1, n);
		mEl=*min_element(Ar.begin()+Lf,Ar.begin()+Rt+1);
		sm+=mEl;
		if(iPd*mEl>MOD)
			iPd=((iPd%MOD)*(mEl%MOD))%MOD;
		else
			iPd*=mEl;
	}

	
	
	cout<<sm<<" "<<iPd%MOD<<endl;	
	    
    return 0;
}
