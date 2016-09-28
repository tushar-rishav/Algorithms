#include <stdio.h>
int main(){
 
	int r,c,pos[4],sum=0;
	scanf("%d %d",&r,&c); // row,column
	const int col=c,row=r;
	int arr[row*col],t_sum=0,init_sum[row*col];
	
	for(int i=0;i<row*col;i++)
		{
			scanf("%d",&arr[i]);
			t_sum+=arr[i];	
			init_sum[i]=t_sum;		// cumulative sum
			
		}
		
	int q,sum_t=0;
	scanf("%d",&q); // queries
	
	while(q--){
		sum_t=0;
		
		scanf("%d %d %d %d ",&pos[0],&pos[1],&pos[2],&pos[3]);
		pos[0]--;
		pos[1]--;
		pos[3]--;
		pos[2]--;
		for(int i=pos[0] ;i<=pos[2];i++)
			sum_t += init_sum[ i*col +pos[3] ]-init_sum[ i*col + pos[1]-1 ];  
		printf("%d\n",sum_t);
				
		
	}
	
	
return 0;
}