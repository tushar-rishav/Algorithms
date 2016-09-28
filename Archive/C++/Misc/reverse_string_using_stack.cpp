/*
	Simple implementation of Stack
*/
#include <bits/stdc++.h>
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
using namespace std;

int main(){

	stack <char> inp_stack;
	char ch[100];
	string s;
	int l;
	
	cout<<"Enter the word\n";
	cin>>s;
	l = s.size();
	
	for(int i=0 ; i < l;i++ ){
		inp_stack.push(s[i]);
	}
	for(int i=0 ; i < l;i++ ){
		ch[i] = inp_stack.top();
		inp_stack.pop();
	}
	for(int i=0 ; i < l;i++ )
		cout<<ch[i];
	cout<<endl;


	return 0;
}