#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

vector<long> cnt;

int main() {
  	std::ios_base::sync_with_stdio(false);
  	long i=0,m_cnt=0,cnt=0;
  	int pos=0;
  	char ch,tmp='-',b_ch=(char)123;
  	ch=getchar();
  	
  	while(ch!='\n'){
  	
  	if(tmp!=ch)
  		{
  			// do something when repition ends  		
  			if(m_cnt<cnt && b_ch > tmp)
  				{	printf("%c %ld\n",tmp,cnt);
  					m_cnt=cnt;
  					b_ch=tmp;
  				}
  			tmp=ch;
  			cnt=0;
  		}
  	cnt++;	
  	
  	ch=getchar();
  	}
  	cout<<b_ch<<endl<<m_cnt;
  	
  	
  	return 0;
  	
 }
