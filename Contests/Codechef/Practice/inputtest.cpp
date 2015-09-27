#include <stdio.h>
#include <iostream>

using namespace std;
int main(){
	std::ios_base::sync_with_stdio(false);
	long long n,k,a,count=0;
	cin>>n;
	cin>>k;
	while(n--){
	
	cin>>a;
	if(!(a%k))
		count++;
	
	}
	cout<<count;
	
	return 0;

}
