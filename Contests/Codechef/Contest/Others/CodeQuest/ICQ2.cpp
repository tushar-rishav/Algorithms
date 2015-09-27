#include <stdio.h>

int main(){
	
	int t;
	long long n,count;
	scanf("%d",&t);
	while(t--){
	count=0;
	scanf("%lld",&n);
	
	while(!(n%2)){
		count++;
		n=n/2;
	
	}
	printf("%lld\n",count);
	
  }
	

return 0;
}
