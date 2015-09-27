#include <stdio.h>
long long play(int I, long long N, int Q){

	if(N%2){  // odd
		
		if(I==Q)
			return (N-1)/2;
		else
			return (N+1)/2;	
	
	}
	
	else	
		return N/2;  // even
	

}
int main(){

	int t,g,i,q;
	long long op,n;
	scanf("%d",&t);
	
	while(t--){
	
		scanf("%d",&g);
		while(g--){
		
			scanf("%d %lld %d",&i,&n,&q);
			op=play(i,n,q);
			printf("%lld\n",op);
		
		}
	}	
	
	return 0;
}
