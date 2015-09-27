#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);
	
	int t,pm,sum,count=0,j=1;
	string shy;
	cin>>t;
	
	while(t--){
	sum=0;count=0;
	cin>>pm;
	cin>>shy;
	if(shy[0]-'0')
		sum+=(shy[0]-'0');
	for(int i=1;i<pm+1;i++){
		
		if(i>sum && (shy[i]-'0'))
			{
				count+=(i-sum);
				
				sum+=(shy[i]-'0')+count;
			}
		else	
			{
				sum+=(shy[i]-'0');  // no of people who have clapped
				//cout<<sum<<endl;
			}
	
	}
	
	cout<<"Case #"<<j<<": "<< count<<endl;
	j++;
	
	}
	
	return 0;
	
	
}
