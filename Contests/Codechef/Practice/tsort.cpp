#include <stdio.h>
#include <stdlib.h>

int comp (const void * elem1, const void * elem2)
{
  int f = *((int*)elem1);
  int s = *((int*)elem2);
  if (f > s) return  1;
  if (f < s) return -1;

  return 0;
}

int main(){

int *num,t,c,i=0,j;
 scanf("%d",&t);
 c=t;
 num=(int*)malloc(t*sizeof(int));
 while(t--){
	 scanf("%d",&num[i]);
	 i++;
}
 qsort (num,c,sizeof(int), comp);
for(j=0;j<c;j++)
	if(num[j]>=0)
		printf("%d\n",num[j]);

return 0;
}
