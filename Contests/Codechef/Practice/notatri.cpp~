#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> l;
vector<int> a;

int main() {
  	std::ios_base::sync_with_stdio(false);
 	int n,j,count,sum,big,ans;
 	long s,tmp;
	while(true){
		j=0;
		big=-1;
		sum=0;
		ans=0;
		cin>>n;
		if(!n)
			break;
				
		for (int i = 0; i < n; ++i) { 
		cin>>s;
		if(big<s)
			big=s;
		l.push_back(s); 
		}
		sort(l.begin(),l.end());	
		count=n;
		for(int i=0;i < 2*big+1;i++)
			{
				if(l[j]==i)
					{
							if(j<n)
							{
								
								
								
								if(l[j]==l[j+1]){         // pain here
								tmp=l[j];					
								for(;;)
									{
										if(l[j]!=tmp)
											{
												i+=1;
												break;
											
											}	
										count--;
										++j;
									
									}
									a.push_back(count);	
								}
								if(l[j]!=l[j+1]){	
									count-=1;
									++j;	
									a.push_back(count);
								}
								
							
							}
							
					}
				
				else	
					a.push_back(count);	
			}
		
		for(int y=0;y<(n-1);y++)
			{
				for(int x=y+1;x<n;x++)
					{
						sum=l[y]+l[x];
						if(a[sum])
							ans+=a[sum];
					
					}
			}
			cout<<ans<<endl;
		l.clear();
		a.clear();
		
		}	
  	

  return 0;
}
