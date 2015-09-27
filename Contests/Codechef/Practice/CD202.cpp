#include <stdio.h>
 
int main(){
 
char sent[101],abc[101];
int len=0,i;
 
gets(sent);
while(sent[len]!='\0')
	len++;
	
 
for(i=0; i<len ;i++){
 
	if(sent[i]=='z' && i && i != (len-1)){
		if(sent[i-1]==sent[i+1]){
			if(sent[i-1]=='a'||sent[i-1]=='e'||sent[i-1]=='i'||sent[i-1]=='o'||sent[i-1]=='u')
				{
					sent[i]='-';
					sent[i+1]='-';
				}
		}
	}
}
i=0;
while(i<len){
	if(sent[i]!='\0')
	printf("%c",sent[i]);
	i++;
}
 
return 0;
}
 
