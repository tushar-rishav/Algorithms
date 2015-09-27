#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  	std::ios_base::sync_with_stdio(false);
	long t;
	long long c=0;
	string ch;
	cin>>t;
	while(t--){
	cin>>ch;
	c=count(ch.begin(),ch.end(),'4');
	cout<<c<<endl;
	}	


	return 0;
}
