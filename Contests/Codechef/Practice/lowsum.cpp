#include <stdio.h>
#include <stdlib.h>
int comp (const void * elem1, const void * elem2)
{
  long f = *((long*)elem1);
  long s = *((long*)elem2);
  if (f > s) return  1;
  if (f < s) return -1;
 
  return 0;
}
 
long *A,*B,*sum;
 
int main(){
 
	int T,K,Q,q,l=0;
	
	
	scanf("%d",&T);
	while(T--){
	
	scanf("%d %d",&K,&Q); // no of chefs and queries
	A=(long*)malloc(K*sizeof(long));
	B=(long*)malloc(K*sizeof(long));
	sum=(long*)malloc(K*K*sizeof(long));
	
	
	for(int i=0;i<K;i++)
		scanf("%ld",&A[i]);
	for(int i=0;i<K;i++)
		scanf("%ld",&B[i]);	
	scanf("%d",&q);
	
	for(int i=0;i<K;i++)
	{
		for(int j=0;j<K;j++)
			{
				sum[l]=A[i]+B[j];
				l++;
			}
	}
	
	qsort (sum,l,sizeof(long), comp);
	printf("%ld\n",sum[q-1]);
	free(A);
	free(B);
	
	} 
 
 
return 0;
}
