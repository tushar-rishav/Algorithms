#include <stdio.h>
#include <stdlib.h>
int main(){
	
	int t,n,count,*players;
	scanf("%d",&t); // test case
	
	while(t--){
	
	//  I/O
		scanf("%d",&n); 
		players=(int*)malloc(n*sizeof(int));
		for(int i=0;i<n;i++)
			scanf("%d",&players[i]);
		count=0;	
		
		for(int i=0;i<n;i++){
	
		if(!i)
			{
				if((players[0]!=players[1])) 
					count++;
			}
		else if(i==n-1) 
			{
				if(players[n-1]!=players[n-2]) 	
					count++;
			}
		
		else if((players[i]!=players[i-1]) || (players[i]!=players[i+1]) )	
				count++;
		}
			printf("%d\n",count);
	
	
	}

	return 0;
}
