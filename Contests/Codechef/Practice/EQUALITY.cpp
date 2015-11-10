#include <iostream>
using namespace std;
int main()
{
	long int t,n;
	scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld",&n);
		long long int a[n],i,s=0,k;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			s=s+a[i];
		}
		for(i=0;i<n;i++)
		{
			k=s-(n-1)*a[i];k=k/(n-1);
			printf("%lld ",k);
		}
		printf("\n");
	}
	return 0;
}  