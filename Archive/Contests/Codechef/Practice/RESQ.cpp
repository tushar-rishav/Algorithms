#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector<long long> n;
int main(){
	std::ios_base::sync_with_stdio(false);
	int t;
	long long e;
	
	cin>>t;
	while(t--){
	cin>>e;
	
	for(int i=1;i*i<=e;i++){
		if(e%i==0)
			{
				n.push_back(abs(i-e/i) );
				
			}		
		}
	sort(n.begin(),n.end());
	cout<<n[0]<<endl;		
	n.clear();	
	}
	
	
	
 
	return 0;
}
 