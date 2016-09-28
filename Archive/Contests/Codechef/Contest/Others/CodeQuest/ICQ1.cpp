#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(){
	std::ios_base::sync_with_stdio(false);
	int t,ch,l,k;
	string s;
	long long count=0;
	cin>>t;
	while(t--){
	count=0;
	cin>>s;
	l=s.size();
 	k=0;
	while(k<l) {
		
		if(s[k]==48&&s[k+1]==49)
			{	
					count++;
					k+=2;
			}
		else	
			k++;
		
	}
	
	cout<<count<<"\n";
	
  }
	
 
return 0;
}
 
 
