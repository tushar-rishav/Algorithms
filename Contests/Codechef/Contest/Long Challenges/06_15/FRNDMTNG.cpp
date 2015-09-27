# include <stdio.h>
 
double func(double a, double b, double c){
	if(b >= a + c)
		return c/b;
	if( b >= c && b >= a ){
		return (b - c)/a*c/b + (2*c*(a + c - b) - (a + c - b)*(a + c - b))/(2*a*b);
	}
	if( b >= c ){
		return	(2*b*c - c*c)/(2*a*b); 
	}
	if( b <= a )
		return b/(2*a);
	return 1 - a/(2*b);
}
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		double T1, T2, t1, t2;
		scanf("%lf%lf%lf%lf",&T1, &T2, &t1, &t2);
		printf("%lf\n", func(T1, T2, t1) + func(T2, T1, t2));
	}
	return 0;
} 