#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;


int main(){
	
	std::ios_base::sync_with_stdio(false);
	int n,k,a,b,m;
	cin>>n;
	while(n--){
	
	cin>>a>>b>>m;
	k=(b-a)/m;
	if (k!=1){
	cout<<k;
	}
	else
		cout<<0;
	cout<<endl;	
	
	
	}
	return 0;
}
