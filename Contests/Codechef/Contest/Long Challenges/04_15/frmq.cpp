//It's stupid to talk about things you're not. Be yourself and you'll be fine.
#include "stdio.h"
#define gc getchar_unlocked
#define pc(x) putchar_unlocked(x);
#define MAXN 100005
#define MAXLOGN 17
 unsigned int n,m,i,j;
 unsigned long long ans = 0;
inline unsigned int min(unsigned int a, unsigned int b)
{
    if( a < b)
    {
        return a;
    }
    else {
        return b;
    }
}
inline unsigned int max(unsigned int a, unsigned int b)
{
    if( a > b)
    {
        return a;
    }
    else {
        return b;
    }
}
 
unsigned int M[100005][17];
unsigned int A[100005];
unsigned int logarithm[20] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072};
    inline void writeInt (unsigned long long  n)
    {
        register unsigned long long  N = n, rev, count = 0;
        rev = N;
        if (N == 0) { pc('0'); pc('\n'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { pc(rev % 10 + '0'); rev /= 10;}
        while (count--) pc('0');
    }
 
inline void scanint(unsigned int &x)
{
    register unsigned int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
inline void Compute_ST(unsigned int N){
   register unsigned int i,j;
    for(i=0;i <= N;++i)
        M[i][0]=i;
    for(j=1;logarithm[j] <= N ;++j){
        for(i=0;i+(logarithm[(j-1)])< N;++i){
            if(A[M[i][j-1]]>=A[M[i+(logarithm[(j-1)])][j-1]])
                M[i][j]=M[i][j-1];
            else
                M[i][j]=M[i+(logarithm[(j-1)])][j-1];
        }
    }
}
inline unsigned int RMQ(register unsigned int s,register unsigned int e){
   register unsigned int k=31- __builtin_clz(e-s+1); // k = log(e-s+1)
    if(A[M[s][k]] >= A[M[e-logarithm[k]+1][k]])
        return A[M[s][k]];
    return A[M[e-(logarithm[k])+1][k]];
}
 
 
int main()
{
    
    scanint(n);
    for(i = 0; i < n; ++i)
    {
        scanint(A[i]);
    }
    Compute_ST(n);
 
    scanint(m);
    scanint(i);
    scanint(j);
 
    while ( m--){
 
        ans +=RMQ(min(i,j),max(i,j) ) ;
        i += 7;
        j += 11;
        while( i >= n-1)
        {
                i -=(n-1);
        }
        while( j >= n)
        {
            j -= n;
        }
    }
    writeInt(ans);
 
    return 0;
}
 
