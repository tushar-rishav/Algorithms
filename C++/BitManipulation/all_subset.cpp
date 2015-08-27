/*
	generate all the possible subsets of a set
*/
	
#include <bits/stdc++.h>

#define pb push_back
#define vci vector< int >

using namespace std;

void subset( vci &A ){
	int N =  A.size();
	for(int i =0 ; i< (1<<N) ; ++i ){			// total possible permutation is 2**N. 

		for(int j=0;j<N;j++){
			if(i & (1<<j) )			// if jth bit is set in i
				cout << A[j]<<",";
		}
		cout<<endl;
	}


}

int main(){

	int N,temp;
	vci A;
	cout<< "Enter the number of elements of set:\t";
	cin>>N;
	cout<< "Enter number of elements of set:\n";
	
	for(int i =0;i<N;i++){
		cin>>temp;
		A.pb(temp);
	}
	subset(A);

	return 0;
}