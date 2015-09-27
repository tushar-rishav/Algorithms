#include <bits/stdc++.h>
# define vci vector<int>
using namespace std;
inline int count1(int n){
	int count = 0;
	while(n){
	n = n & (n-1);
	count++;
	}
	return count;

}
inline bool compare (int i,int j) { return (i>j); }
int main(){

std::ios_base::sync_with_stdio(false);
int t,n,k,temp,sm,bit;
vci num;

cin>>t;
while(t--){
	sm=0;
	cin>>n>>k;
	while(n--){
		cin>>temp;
		bit=count1(temp);
		num.push_back(bit);
	}
	sort(num.begin(),num.end(), compare );
	for(int i=0;i<k;i++)
		sm+=num[i];
	cout<<sm<<endl;
	num.clear();
}
return 0;
}
