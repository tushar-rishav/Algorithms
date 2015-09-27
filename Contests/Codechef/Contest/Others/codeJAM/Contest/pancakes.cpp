#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false);

	int t,j=1,c=0,d,mx=-1,n;
	
	cin>>t;
	while(t--){
	
	c=0;
	mx=-1;
	cin>>d;
	for(int i=0;i<d;i++){
		cin>>n;
		if(mx<n)
			mx=n;  // fetch the maximum of all the pancakes in plate before starting
			
	}
	while(true){
	
		if(mx){
		if(mx%2==0){
				mx=mx/2;
				c++;
			}
		else{
				mx-=1;
				c++;	
			}
		if(mx==1)
		{
			c++;
			break;
		
		}
	 }
	 else
	 break;		
	}
	
	cout<<"Case #"<<j<<": "<<c<<endl;
	j++;
	
	}


	return 0;
}
