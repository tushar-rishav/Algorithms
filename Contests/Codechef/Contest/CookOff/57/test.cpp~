#include<iostream>
#include <stdio.h>
#include<algorithm>
#include <vector>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	long int t,n;
	scanf("%ld",&t);
	while(t--)
	{
		cin>>n;
		long long int a[n],i,s=0,k;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			s+=a[i];
		}
		for(i=0;i<n;i++)
		{
			k=s/(n-1)-a[i];
			cout<<k<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
