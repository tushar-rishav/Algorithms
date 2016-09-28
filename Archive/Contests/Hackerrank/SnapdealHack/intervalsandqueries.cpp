# include <bits/stdc++.h>
# define ll long long
using namespace std;

int f(pair<int, int> ele, int a, int b)
{
	if(ele.first >= a && ele.second <= b)
		return 1;
	else return 0;
}
int main()
{
	int n,q, x, y, s, e, a, b;
	cin>>n>>q;
	vector<pair<int, int> > v;
	for(int i=0; i<n; i++)
	{
		cin>>s>>e;
		v.push_back(make_pair(s,e));
	}
	while(q-- )
	{
		cin>>a>>b>>x>>y;
		int ans = 0;
		for(int i=x; i<=y; i++)
			ans += f(v[i], a, b);

		cout<<ans<<endl;
	}
}