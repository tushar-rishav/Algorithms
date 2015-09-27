#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int comp (const void * elem1, const void * elem2)
{
  	
  char f = *((char*)elem1);
  char s = *((char*)elem2);
  if (f > s) return  1;
  if (f < s) return -1;
  return 0;
}

//char s[100],integerPos[100],alphaPos[100],integers[100],alpha[100];
int main(){
	std::ios_base::sync_with_stdio(false);
	int t,ch;
	char *s,*integerPos,*alphaPos,*integers,*alpha;
	string gg;
	long long l,j=0,k=0,m=0,n=0;

	cin>>t;
	while(t--){
	
	cin>>gg;
	l=gg.size();

	s=(char*)malloc(l*sizeof(char));
	integerPos=(char*)malloc(l*sizeof(char));
	alphaPos=(char*)malloc(l*sizeof(char));
	integers=(char*)malloc(l*sizeof(char));
	alpha=(char*)malloc(l*sizeof(char));
	
	for(int h=0;h<l;h++)
		s[h]=gg[h];
	
	//qsort (&s,l,sizeof(char),comp); 
	for(long long i=0;i<l;i++){
			if(s[i]>47 && s[i]<58)
				{
					integers[j]=s[i];
					integerPos[j]=i;
					j++;
	
				}
			else
				{
					alpha[k]=s[i];
					alphaPos[k]=i;
					k++;
	
				}	
			}
		 /*
		 integers=string(integers);
		 alpha=string(alpha);
		 sort(integers.begin(),integers.end()); // words have been sorted
		 sort(alpha.begin(),alpha.end());
		 */
		 qsort (alpha,k,sizeof(char),comp);
		 qsort (integers,j,sizeof(char),comp); 
		 for(long long i=0;i<j;i++){
		 
		 		s[integerPos[i]]=(char)integers[i];
		 }
		 for(long long i=0;i<k;i++){
		 
		 		s[alphaPos[i]]=(char)alpha[i];
		 }
		for(int m=0;m<l;m++)
		 cout<<s[m];
		cout<<"\n"; 
		 //cout<<s<<"\n";
		 	
	}


return 0;
}
