#include <iostream>
using namespace std;
 
int main()
{
	int t;
	string s,c;
	c="";
	cin>>t;
	while(t--){
		
		cin>>s;
		for(auto it=s.begin(); it!=s.end();it++){
			if(*it!=*(it+1)){
				c+=*it;
			}
		}
		cout<<c<<endl;
		c="";
	}
    return 0;
}