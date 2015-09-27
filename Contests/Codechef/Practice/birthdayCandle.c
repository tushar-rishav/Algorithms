#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

  int *nAr,i,t,num;


  scanf("%d",&t); // test cases
  nAr=(int*)malloc(10*sizeof(int));

  while(t--){

    scanf("%d",&num);


    for(i=0;i<10;i++){
      nAr[i]=num/((int)pow(10,9-i));
      num%=(int)pow(10,9-i);
      printf("|%d|",num);
    }


    free(nAr);
  }



  return 0;

}
