#include <stdio.h>
int main(){
	
	int t;
	long long N,count=0,sum=0,i=0,digit;
	scanf("%d",&t);
	
	while(t--){
	
	scanf("%lld",&N);
	i=0;
	sum=0;
	while(i<N-1) {
		scanf("%lld",&digit);
		sum+=digit;
		i++;
	}
	count=(N*(N+1)/2)-sum;
	printf("%lld\n",count);
	
  }	

return 0;
}
