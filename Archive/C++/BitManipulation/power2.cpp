/*
	check if a given number is a power of 2
*/

#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int x){
return (x && !(x & (x-1)));
}
int main(){

cout<<isPowerOfTwo(4)<<endl;
cout<<isPowerOfTwo(5)<<endl;
return 0;

}
