#include <stdio.h>
#include <stdlib.h>

int search(char,char []);
int input(void);
int countHole(char [],int);


int main(){

	int t,i,*holes;
	char dummy;
	scanf("%d",&t);
	scanf("%c",&dummy);
	holes=(int*)malloc( t*sizeof(int)  );

	for(i=0;i<t;i++)
			holes[i]=input(); // store the count of holes

	for(i=0;i<t;i++)
		printf("%d\n",holes[i]); // print the holes

	return 0;
}

int input(){

	int hole=0,len=0;
	char word[100],ch;
	gets(word);


	while(word[len]!='\0')
		len++;

		hole=countHole(word,len);
		return hole;
	}
int search(char ch,char set[]){

	int lt=0,rt=6,md=3;
	while(1){

		if(ch==set[md])
		{
			if(ch=='B')
				return 2; //found
			return 1;
		}
			if(lt>=rt+1)
				return 0; //not found

				if(ch>set[md])
					lt=md+1;
					else
						rt=md-1;
						md=(lt+rt)/2;

}

}


int countHole(char word[],int size){
	int i,count=0;
	char set[7]={'A','B','D','O','P','Q','R'};
	int res=0;

	for(i=0;i<size;i++){
		res=search(word[i],set);
		if(res)
		{	if(res==2)
				count+=2;
			else
					count++;
		}
	}
	return count;
}
