#include <iostream>
#include <algorithm>
using namespace std;
 
int main()
{
    int t;
    string s;
    cin>>t;
    while(t--){
    	cin>>s;
    	reverse(s.begin(),s.end());
    	cout<<s<<endl;
    	
    }
    return 0;
}