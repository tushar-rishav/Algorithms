#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <cmath>
#include <vector>
using namespace std;
 

int main()
{
	ios_base::sync_with_stdio(false);
	int t,n,brk=0;
	long long tof;
	vector <long long> tofV;
	cin>>t;
	
	while(t--){
	
	cin>>n;
	
	while(n--){
			cin>>tof;
			tofV.push_back(tof);
		}
	for(int i=0;i<tofV.size()-1;i++){
		for(int j=i+1;j<tofV.size();j++)
				{
					if(abs(tofV[i]-tofV[j])>1)
					{
					cout<<"BAD"<<endl;
					brk=1;
					break;
						
					}
				
				}
				if(brk)
					break;
	}
	if(!brk)
		cout<<"GOOD"<<endl;
	brk=0;
	tofV.clear();
	
	}
	
	
	
	return 0;
}
