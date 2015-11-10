# include <stdio.h>
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
 
int t,count,n,i,j;
scanf("%d",&t);
while(t--){
int *wt_of_pies,*wtlmt_of_rack;
count=0;
scanf("%d",&n);
wt_of_pies=(int*)malloc(n*sizeof(int));
wtlmt_of_rack=(int*)malloc(n*sizeof(int));
 
for(i=0;i<n;i++)
	scanf("%d",&wt_of_pies[i]);
 
for(i=0;i<n;i++)
	scanf("%d",&wtlmt_of_rack[i]);
 
 
 
 
qsort (wt_of_pies,n,sizeof(	int), comp);
qsort (wtlmt_of_rack,n,sizeof(int), comp);
 
 
for(i=0;i<n;i++){
 
	for(j=0;j<n;j++){
		if(wt_of_pies[i]<=wtlmt_of_rack[j])
			{
				++count;
				wtlmt_of_rack[j]=0;
				break;
			}
	}
 
}
 
 
printf("%d\n",count);
 
 
 
free(wt_of_pies);
free(wtlmt_of_rack);
 
}
 
 
return 0;
}