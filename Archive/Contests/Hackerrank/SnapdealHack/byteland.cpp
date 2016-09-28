# include <bits/stdc++.h>
# define ll long long
# define MOD 1000000007
# define SIZE 3000
using namespace std;
void print( ll **table, int n, int m)
{

	for (int i = 1; i <= n ; ++i)
	{
		for (int j=1; j<=m; j++)
		{
			cout<<table[i][j]<<" ";
		}
		cout<<endl;
	}
}

ll find(int **a, int n, int m)
{

/*	ll a1 = find(a , n-1 , m-1 );
	ll b1 = find(a, n-1, m);
	ll c1 = find(a, n, m-1);
*/
	ll **table = new ll*[n+1];
	
	ll **left = new ll*[n+1];
	ll **up = new ll*[n+1];
	ll **diag = new ll*[n+1];
	for(int i=0; i<=n; i++)
	{
		table[i] = new ll[m+1];
		left[i] = new ll[m+1];
		up[i] = new ll[m+1];
		diag[i] = new ll[m+1];
	}

	for(int i=0; i<=m; i++)
		table[0][i] = left[0][i] = up[0][i] =   diag[0][i] = 0;

	for(int i=0; i<=n; i++)
		table[i][0] = left[i][0] = up[i][0] =  diag[i][0] = 0;

	table[1][1] = a[1][1];
	left[1][1] = a[1][1];
	up[1][1] = a[1][1];
	diag[1][1] = a[1][1];
/*	for (int i = 2; i <= n; ++i)
		table[i][1] = (table[i-1][1] * a[i][1])%MOD;
	
	for (int i = 2; i <= m; ++i)
		table[1][i] = (table[1][i-1] * a[1][i])%MOD;

*/
	for(int i=1; i<=n ; i++ )
	{
		for(int j=1; j<=m; j++)
		{
			ll a1 , b1, c1;
			int k = i-1;
			a1 = b1 = c1= 0;
			/*while( k > 0 )
			{
				a1  = (a1 + table[k][j])%MOD;
				k--;
			}
			k = j-1;
			while( k > 0 )
			{
				b1  = (b1 + table[i][k])%MOD;
				k--;
			}*/
	
				
			a1 = left[i][j-1];
			b1 = up[i-1][j];
			c1 = diag[i-1][j-1];			
			if(i != 1 || j != 1) 
			{
				table[i][j] = ( (a1 + b1 + c1)% MOD * (a[i][j] % MOD ) ) % MOD;
				left[i][j] = (a1 + table[i][j])%MOD;
				up[i][j] = (b1 + table[i][j])%MOD;
				diag[i][j] = (c1 + table[i][j])%MOD;
			}
		}
	}
	
	//print(table, n, m);
	/*print(up, n, m);
	print(left, n, m);*/
	return table[n][m];
}
int main()
{
	int n, m;

	int **a;

	cin>>n>>m;

	a = new int*[n+1];
	for(int i=0 ;i<=n ; i++)
		a[i] = new int[m+1];

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			cin>>a[i][j];
		}
	}

	ll ans = find(a, n, m);
	cout<<ans<<endl;
}