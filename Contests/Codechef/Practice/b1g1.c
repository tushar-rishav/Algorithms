#include<stdio.h>
#include <string.h>
#define MAX 201
int count[52]={0};
int main()
{
	int t;
    scanf("%d",&t);
    while(t--){
               char str[MAX]; int i=0,res=0;
               scanf("%s",str);
              
              for(i=0;i<52;i++)
               	count[i]=0; 
               
               for(i=0;i<strlen(str);i++)
               {   if(str[i]>='a'&&str[i]<='z') 
               			count[str[i]-'a'+26]++;      // mapping 
                   else 
                   		count[str[i]-'A']++; 
                  
               }
                 for(i=0;i<52;i++)   
                 {
                 	if(count[i]%2==0)
                   		res+=count[i]/2;  			// counting
                    else res+=(count[i]+1)/2;
                 }
                 	printf("%d\n",res);
               
              }
    
    return 0;
    }
