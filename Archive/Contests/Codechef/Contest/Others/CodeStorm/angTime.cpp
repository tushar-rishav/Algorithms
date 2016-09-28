#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int min(int x, int y) { return (x < y)? x: y; }

int calcAngle(int h, int m)
{
   
    if (h == 12) h = 0;
    if (m == 60) m = 0;
    int hour_angle = 0.5 * (h*60 + m);
    int minute_angle = 6*m;

    int angle = abs(hour_angle - minute_angle);

    angle = min(360-angle, angle);

    return angle;
}

int main()
{
	ios_base::sync_with_stdio(false);
	
	int t,min=0,hr=0,ang,a,b;
	string time;
	cin>>t;
	while(t--){
		cin>>time;
		min=(time[3]-'0' )*10+time[4]-'0';
		hr=(time[0]-'0')*10+time[1]-'0';
		hr=hr>12?hr-12:hr;
	    ang=calcAngle(hr,min);
	    if(!(ang%5))
	    	cout<<"YES"<<endl;
	    else
	    	cout<<"NO"<<endl;	
    }
    return 0;
}
