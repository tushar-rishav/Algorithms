# include <stdio.h>
 
int main()
{   char ch,a[102]; int i=0,l;
    while(1)
    
    {scanf("%c",&ch);
       if(ch == 10)
    break;
    a[i++]=ch;
    if(ch =='a' ||ch =='e'||ch=='i'||ch =='o'||ch =='u')
    {
    
    scanf("%c");
    scanf("%c");
    } 
    }
    for(l=0;l<i;l++)
    printf("%c",a[l]);
return 0;
}
 