#include <stdio.h>
 
char scale[100];
int  main(){
 
	long t;
	long long n,dummy,x,ways;
	char ch;
	
	scanf("%ld",&t);
	
	while(t--){
		x=0;
		scanf("%lld",&dummy);
		ch=getchar();
		while(ch!='\n'){
	
		if(ch=='T')
			x+=2;
		else
			x+=1;
		ch=getchar();	
			
	}
	
	scanf("%lld",&n);
	long long nm,dn,p;
	p=(12*n)/x;
	nm=12*n*p;
	dn=(p*(p+1)*x)/2;
	ways=nm-dn;
	
	/*if(!((12*n)%x))
		ways=12*n;
	else
		ways=(12*n-x);
	*/
	printf("%lld\n",ways);	
	
}	
 
 
	return 0;
}
 