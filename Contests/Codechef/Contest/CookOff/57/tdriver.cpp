#include<iostream>
#include <stdio.h>
#include<algorithm>
#include <vector>

using namespace std;
vector<long long> x;
vector<long long> y;
int main()
{
	ios_base::sync_with_stdio(false);

	long long t,n,a,b,p,q;
	cin>>t;
	while(t--){
	
	cin>>n;
	cin>>a>>b;
	for(long i=0;i<n;i++ )
		{
			cin>>p>>q;
			x.push_back(p);
			y.push_back(q);
		
		}
	register long long sum=0;
	for(long i=0;i<n-1;i++)
		for(long j=i+1;j<n;j++)
			{
				sum+=a*abs(x[i]-x[j])>b*abs(y[i]-y[j])?a*abs(x[i]-x[j]):b*abs(y[i]-y[j]);	
			}
	cout<<sum<<endl;
	x.clear();
	y.clear();
	}

	return 0;
	
}
