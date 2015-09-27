#include <bits/stdc++.h>
#define NDEBUG      // to suppress assertion error message
#define FORi(i,j,k) for(int i=j;i<k;i++)
#define FORll(i,j,k) for(long long i=j;i<k;i++)
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;

#define ll long long
#define ull unsigned long long
#define db double
#define vci vector<int>
#define vcll vector<long long>
#define MOD 1000000007

using namespace std;
int getMid(int s, int e) {  return s + (e -s)/2;  }
 
int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
 
    if (se < qs || ss > qe)
        return 0;
 
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
 
void updateValueUtil(int *st, int ss, int se, int i, int diff, int index)
{
    if (i < ss || i > se)
        return;
 
    st[index] = st[index] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
 
void aupdateValue(vcll &arr, int *st, int n, int i, int new_val,int r)
{
   
 
    int diff;
    ll nv=arr[i]+new_val;
    if(r){
        arr[i] = nv;
        diff = nv - arr[i];
    }
    else{
        arr[i]%=MOD;
        new_val=(nv)%MOD;
        diff = new_val-arr[i];
    }

    updateValueUtil(st, 0, n-1, i, diff, 0);
}
void mupdateValue(vcll &arr, int *st, int n, int i, int new_val,int r)
{
    
    
    
    int diff;
    ll nv=arr[i]*new_val;
    
    if(r){
        arr[i] = nv;
        diff = nv - arr[i];
    }
    else{
        arr[i]%=MOD;
        new_val=(nv)%MOD;
        diff = new_val-arr[i];
    }
    
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 

int getSum(int *st, int n, int qs, int qe)
{
    
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 

int constructSTUtil(vcll arr, int ss, int se, int *st, int si)
{
    
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 

int *constructST(vcll arr, int n)
{
     int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *st = new int[max_size];
 
    constructSTUtil(arr, 0, n-1, st, 0);
 
   
    return st;
}
 
int main()
{   std::ios_base::sync_with_stdio(false);
    ll N,Q,el;
    vcll arr;
    cin>>N>>Q;
    FORi(i,0,N){
        cin>>el;
        arr.push_back(el);
    }

    ll n = N;
 
    // Build segment tree from given array
    int *st = constructST(arr, n);
    int first,x,y,v;
    while(Q--){
        cin>>first;
        if(first==1){
            cin>>x>>y>>v;
            FORi(i,x-1,y){
                aupdateValue(arr, st, n, i, v,1);
                aupdateValue(arr, st, n, i, v,0);
            }
            // FORi(i,0,N)
            //     cout<<arr[i]<<",";
            // cout<<endl;

        }
        else if(first==2){
            cin>>x>>y>>v;
            FORi(i,x-1,y){
                mupdateValue(arr, st, n, i, v,1);
                mupdateValue(arr, st, n, i, v,0);
            }
            // FORi(i,0,N)
            //     cout<<arr[i]<<",";
            // cout<<endl;
        }
        else if(first==3){
            cin>>x>>y>>v;
            FORi(i,x-1,y){
                aupdateValue(arr, st, n, i, v-arr[i],1);
                
            }
            // FORi(i,0,N)
            //     cout<<arr[i]<<",";
            // cout<<endl;
        }
        else if(first==4){
            cin>>x>>y;
            cout<<getSum(st, n, x-1, y-1)%MOD;
            cout<<endl;
            // ll sum=0;
            // FORi(i,x-1,y){
            //     sum+=arr[i];
            //     sum%=MOD;
            // }
            // cout<<sum<<endl;
            // // FORi(i,0,N)
            //     cout<<arr[i]<<",";
            // cout<<endl;
        }
        

    }
   
 
    return 0;
}
