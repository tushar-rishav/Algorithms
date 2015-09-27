#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define i 1
#define j 2
#define k 3

using namespace std;
char table[4][4]={
		{"1","i" ,"j" ,"k"},
		{"i","-1","k" ,"-j"},
		{"j","-k","-1","i"},
		{"k","j" ,"-i","j"}
	};
	
char multiply(int posA,bool signA,int posB,bool signB){

	return table[posA][posB]; 


}

int main(){
	std::ios_base::sync_with_stdio(false);
	char ch;

	cout<<multiply(i,-1,j,1);
	
	return 0;

}
