#include<iostream>
#include<algorithm>
#include <stdio.h>
#include <cmath>
using namespace std;
 

int main()
{
	ios_base::sync_with_stdio(false);

	
	float t,min=0,hr=0,ang,a,b;
	//char time[5];
	string time;
	cin>>t;
	while(t--){
	
	cin>>time;
	
	min=(time[3]-'0' )*10+time[4]-'0';
	hr=(time[0]-'0')*10+time[1]-'0';
	hr=hr>12?hr-12:hr;
	
	float h=hr*30+(float)min/2;
	a=min*6-h;
	if(!((int)a%5))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;	
		
	}

	
	return 0;


}
