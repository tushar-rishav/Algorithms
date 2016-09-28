#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int c[100],arr[100],ans[100],m[100],sm=0,count=0;
        memset(m,0,sizeof(m));
        memset(arr,0,sizeof(arr));
        memset(ans,0,sizeof(ans));
        int k1=0;
 
        for(int i=1;i<=n;i++)
        {
            cin>>c[i];
            if(c[i]>=n)
            {
                count=1;
            }
            sm = sm + c[i];
            if(c[i]!=0)
            {
                m[i]=1;
                arr[k1++] = i;
                c[i] = c[i] - 1;
            }
        }
 
        if(sm!=n)
            count=1;
 
        if(count==0)
        {
 
        for(int i=0;i<(k1-1);i++)
        {
            ans[arr[i]]= arr[i+1];
        }
        ans[arr[k1-1]]=arr[0];
 
 
        for(int i=1;i<=n;i++)
        {
            if(m[i]==0)
            {
                for(int j=1;j<=n;j++)
                {
                    if(i!=j)
                    {
                        if(c[j]!=0)
                        {
                            c[j]=c[j]-1;
                            ans[i]=j;
                            break;
                        }
                    }
                }
            }
        }
 
 
 
        for(int i=1;i<n;i++)
        {
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[n]);
        }
        else if(count==1)
        {
            printf("-1\n");
        }
    }
} 