#include <stdio.h>
void scan_positive_int(int *a)
{
int x=0;
register int c=getchar_unlocked();
for(; c>47 && c<58 ; c = getchar_unlocked())
{
x = (x<<1) + (x<<3) + c - 48;
}
*a=x;
}
int main()
{
int n,k,t,count=0;
scan_positive_int(&n);
scan_positive_int(&k);
while(n>0)
{
n--;
scan_positive_int(&t);
if(t%k==0)
count++;
}
printf("%d",count);
return 0;
} 