#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector<long> a;
int main(){
	std::ios_base::sync_with_stdio(false);
	int t,l;
	long e;
	cin>>t;
	while(t--){
	cin>>l;
	
		while(l--){
			cin>>e;
			a.push_back(e);
		
		}
		sort(a.begin(),a.end());
		cout<<a[a.size()-1];
		cout<<endl;
		a.clear();
	}
	
	
	return 0;
}