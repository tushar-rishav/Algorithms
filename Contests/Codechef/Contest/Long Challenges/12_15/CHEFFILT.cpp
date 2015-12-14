#include <bits/stdc++.h>
# define ll long long
# define MOD 1000000007
# define testcases() ll var;  cin>>var; while(var--)
# define rep(i, n) for( ll (i) = 0; (i) < (n); (i)++)
# define repk(i,k,n) for( ll (i) = k; (i) < (n); (i)++)
# define REP(i, n) for( ll (i) = 1; (i) <= (n); (i)++)
using namespace std;

ll guna(int a, int b)
{
    ll ans = 1;
    rep(i, b)
        ans = (ans * a)% MOD;
    return ans % MOD;
}
inline int find_bin_num(char a[])
{
    int s = 0;
    rep(i, 10)
    {
        s *= 2;
        if (a[i] == 'w' || a[i] == '+')
            s += 1;
    }
    return s;
}

ll samjhdari(int rev, short int a[], int n)
{
    int maal_godaam[1025][1024];
    int k = 1024;
    
    int jod[1024] = {0};
    ll ginti[1024];
    
    rep(i, n)
        jod[a[i]]++;
    
    
    rep(i, 1024)
    {
        if(jod[i] == 0)
            ginti[i] = 0;
        else
            ginti[i] = guna(2, jod[i] - 1);     
    }
    memset(maal_godaam, 0, sizeof(maal_godaam));
    ginti[0]= (jod[0]==0?1:( guna(2 ,jod[0])) );
    maal_godaam[0][0] = (ginti[0] == 0?1:ginti[0]);
    REP(i, 1023)
    {
        rep(j, 1024)
        {
            if(ginti[i] == 0)
                maal_godaam[i][j] = maal_godaam[i-1][j];
            else
                maal_godaam[i][j] = (ginti[i] * (maal_godaam[i-1][j] + maal_godaam[i-1][j^i]) % MOD ) % MOD;
        }
    }
    return maal_godaam[1023][rev];
}
int main()
{
    int t,n;
    char babbar_Sher[11], potli[11];
    short int gin_lo_beta[100000], r;
    testcases()
    {
        scanf("%s", babbar_Sher);
        int r = find_bin_num(babbar_Sher);
        scanf("%d", &n);
        rep(i, n)
        {
            scanf("%s", potli);
            gin_lo_beta[i] = find_bin_num(potli);
        }
        printf("%lld\n", samjhdari(r, gin_lo_beta, n) );
    }
}