#include <iostream>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	long n;
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		while(n%10==0)
			n/=10;
		
		if(n==1)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
		}
	}
	return 0;
}  