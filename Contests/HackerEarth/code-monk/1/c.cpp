#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    long long t,x,n,tmp,s;
    bool flag=false;
    vector<long long> gift;
    cin>>t;
    while(t--){
    	s=0;
    	cin>>n>>x;
    	while(n--){
    		cin>>tmp;
    		gift.push_back(tmp);
    	}
    	tmp = gift.size();
    	for(long long i=0;i<tmp;i++){
    		for(long long j = i;j<tmp;j++){
    			s = 0;
    			for(long long p = i;p<=j;p++)
    				s+=gift[p];
    		//	cout<<"|"<<s<<"}"<<endl;
    			if(s==x){
    				flag=true;
    				break;
    			}
    			if(s>x)
    				break;
    			
    			
    		}
    		
    		if(flag)
    			break;
    	}
    	
    	if(flag)
    		cout<<"YES"<<endl;
    	else
    		cout<<"NO"<<endl;
    	gift.clear();
    	flag= false;
    	
    }
    return 0;
}