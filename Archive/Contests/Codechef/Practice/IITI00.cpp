#include <iostream>
#include <vector>
using namespace std;
 
 
int main()
{
	ios_base::sync_with_stdio(false);
	
	vector<int> num;
	int n,k,e,sum1=0,sum2=0;
	
	cin>>n>>k;
	int t=n;
	while(t--){
	
	cin>>e;
	num.push_back(e);
	
	}
	for(int i=n-k;i<n;i++)
		sum1+=num[i];
 
	for(int i=0;i<n-k;i++)
		sum2+=num[i];
	cout<<sum1-sum2<<endl;
	
	return 0;
	
}