#include <stdio.h>
#include <algorithm>
#include <string.h>
long long C(int n, int r)
{
    if (r==0) return 1;
    else 
    	return C(n-1,r-1) * n / r;
}

int comp (const void * elem1, const void * elem2)
{
  int f = *((int*)elem1);
  int s = *((int*)elem2);
  if (f > s) return  1;
  if (f < s) return -1;
  return 0;
}


int main(){

	int t,score[12],k,map[101],temp=101,sum=0;
	long long ways=1;
	memset (map,0,101*sizeof(int));
	scanf("%d",&t);
	
	while(t--){
	
		for(int i=0;i<11;i++)
			{
				scanf("%d",&score[i]);
				map[score[i]]++;
			}
		scanf("%d",&k);	
		qsort (score,11,sizeof(int), comp);
		
		for(int i=10;i>-1;i--)
			{
					if(temp!=score[i]){
						sum+=map[score[i]];
						if(sum>k){
							ways=C(map[score[i]],k-sum+map[score[i]]);
							break;
						}
					
					
					}
						
						temp=score[i];
			}
		printf("%lld\n",ways);
		sum=0;
		temp=101;
	}	
	
	
	return 0;
}
