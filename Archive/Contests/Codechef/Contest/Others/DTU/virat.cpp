#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;


int main(){
	
	std::ios_base::sync_with_stdio(false);
	int n,i=0,neg=0,pos,*p;
	long long prod;
	vector<int> num;
	
	cin>>n;
	while(n--){
		cin>>i;
		num.push_back(i);
		
	}
	sort(num.begin(),num.end());
	
	
	for(int i=0;i<num.size();i++){
		
		if(num[i]>=0)
			{pos=i;break;}
		neg++;	
	
	
	}
	
	if(neg%2){
		
		for(int i=0;i<num.size();i++)
			{
				
				if(num[i]){
					
					prod*=num[i];
				
				}
			
			
			}
			
			cout<<prod<<endl;
	
	}
	
	else if(neg>0 && !(neg%2)){
	
			for(int i=0;i<num.size();i++)
				{
					if(i!=pos-1 && num[i])
						prod*=num[i];
				
				}	
			
			
			cout<<prod<<endl;
	
	}
	else{
	 cout<<num[0]<<endl;
	
	}
	
	
	
	
	return 0;
	}
