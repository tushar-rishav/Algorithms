#include <bits/stdc++.h>
using namespace std;
#define pb  push_back
#define MAXN    10010
#define YES cout<<"YES\n";
#define NO  cout<<"NO\n";
#define mm(v)   memset(v,-1,sizeof(v))
 
int visited[MAXN]={0},n;
vector<int> graph[MAXN];
 
 
int bfs(int u)
{
    queue<int> Q;
    Q.push(u);
    visited[u]=0;
    int v;
 
    while(!Q.empty())
    {
        v=Q.front();
        Q.pop();
        for(int i=0;i<graph[v].size();i++)
        {
            if(visited[graph[v][i]]==-1)
            {
                visited[graph[v][i]]=visited[v]+1;
                Q.push(graph[v][i]);
            }
        }
    }
 
    // now v is the farthest element
    // then too i shd calc it from visited
    int idx=v,tc=-1;
    for(int i=1;i<=n;i++)
    {
        if(tc<visited[i])
        {
            tc=visited[i];
            idx=i;
        }
    }
 
    // now we have farthest point from u i.e idx
    return idx;
}
 
 
 
 
 
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
    //int t;
    //cin>>t;
    // while(t--)
    // {
        int i,a,b;
        cin>>n;
        bool ans=false;
 
 
        // clear all the initials
        for(i=0;i<=n;i++)
            graph[i].clear();
 
 
        for(i=0;i<n-1;i++)
        {
            cin>>a>>b;
            graph[a].pb(b);
            graph[b].pb(a);
        }
 
        // if(n==2 || n==1)
        // {
        //     NO
        //     continue;
        // }
 
        mm(visited);
        int arb=1,start,ending;
        // let initial root be 1
        start=bfs(arb);
        cout<<"start - "<<start<<endl;
 
        mm(visited);
        ending=bfs(start);
        cout<<"ending - "<<ending<<endl;
 
        int diameter = visited[ending];
        cout<<"diameter - "<<diameter<<endl;
        // // let we connect them as there can be atmax one diameter for ans to be true
 
        // graph[start].pb(ending);
        // graph[ending].pb(start);
        // // now if diameter some what less then its true so let start it from the ending point
        // mm(visited);
 
        // int chq=bfs(ending);
        // cout<<"chq - "<<chq<<endl;
        // cout<<"chq distance from "<<ending<<" - "<<visited[chq]<<endl;
        // if(visited[chq]<diameter)   ans=true;
        // else
        // {
        //     // if it find path find till dusra wala strating point so
        //     // case when we have 2 centres
        //     mm(visited);
        //     chq=bfs(start);
        //     if(diameter>visited[chq])   ans=true;
        // }   //ans=false;
 
 
        // if(ans) YES
        // else    NO
    //}
    return 0;
}