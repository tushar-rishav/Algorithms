#include <stdio.h>
#include <stdlib.h>
int main(){

int num,dis=0,i=0,t=10,*mod;
while(t--){
mod=(int*)malloc(42*sizeof(int));
for(i=0;i<10;i++)
	{
		scanf("%d",&num);
		mod[num%42]++;
	}
	for(i=0;i<42;i++){
		if(mod[i])
			dis++;
	}
	printf("%d\n",dis);
	dis=0;
	free(mod);	
}
return 0;
}
