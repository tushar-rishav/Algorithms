#include <stdio.h>
int main(){
 
	long long n,sum=0;
	int t;
	scanf("%d",&t);
	while(t--){
	
	scanf("%lld",&n);
	
			for(long long i=1;(i*i)<=n;i++)
			{
				if(!(n%i))
				{
					if(n!=1)
						{
							if(i!=n/i)
								sum+=(i+(n/i));
							else
								sum+=i;	
						
						}
						
					else
						{sum=1;break;}
				}	
			}
	printf("%lld\n",sum);
	sum=0;	
	}
 
 
return 0;
 
}
