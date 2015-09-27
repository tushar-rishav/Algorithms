#include<stdio.h>
int main()
{
 int x;
 float y;
 scanf("%d%f",&x,&y);
 
 if(x%5==0 && 0.5<=y-x)
   printf("%0.2f",y-x-0.5);
 else
  printf("%0.2f",y);
 
 return 0;
}
