#include <bits/stdc++.h>
#define MAX 100000
#define pub push_back
#define tr(container,it) for(auto it = container.begin(); it != container.end(); ++it )
using namespace std;
bool visit[MAX] = {false};
map <int, vector<int>> adj;

void dfs(int src){
    stack <int> S;
    S.push(src);
    int v;
    while(!S.empty()){
          v = S.top();S.pop();
          visit[v] = true; //cout<<"v "<<v<<endl;
        for(vector<int>::iterator it = adj[v].begin(); it!= adj[v].end(); ++it){
            if(!visit[*it]){    // NOT VISITED THEN PUSH
                S.push(*it);
                visit[*it] = true;  // MARK VISITED
            }
           
        }
          
    }
}

int main(){
    
    int n,m, x,y;
    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int count = 0;
    for(int i = 1;i<=n; i++){
        
        if(!visit[i]){
            count++;
            dfs(i);
            visit[i] = true;
        }
            
    }
    printf("%d\n", count);
        
    return 0;
}
