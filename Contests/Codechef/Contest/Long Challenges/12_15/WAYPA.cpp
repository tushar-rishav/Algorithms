#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef double db;

# define fs first 
# define se second
# define bg begin
# define rbg rbegin
# define en end
# define ren rend
# define mp make_pair
# define pub push_back
# define pob pop_back
# define cl clear
# define em empty
# define fe for_each
# define np next_permutation
# define pp prev_permutation

# define DEBUG(x) cout << '>' << #x << ':' << x << endl;
# define all(c) c.bg(), c.en()
# define rall(c) c.rbg(), c.ren()

# define pll pair < ll, ll >
# define pllit pair < ll, ll >::iterator
# define mll map < ll, ll >
# define mllit map < ll, ll >::iterator
# define msl map < string, ll >
# define mslit map < string, ll >::iterator
# define vll vector< ll >
# define vvll vector< vll >
# define vllit vector< ll >::iterator
# define vc vector<char>
# define vcit vector<char>::iterator
# define sll set< ll >
# define sllit set< ll >::iterator

# define srt(v) sort( v.bg(), v.en() )
# define srtr(v) sort( v.rbg(), v.ren())
# define srtc(v, x) sort( v.bg(), v.en(), x)
# define tr(container, it) for(typeof(container.bg()) it = container.bg(); it != container.en(); it++)
# define rtr(container, it) for(typeof(container.rbg()) it = container.rbg(); it != container.ren(); it++) 
# define present(container, element) (container.find(element) != container.en()) // O(logN) : use in case of Set and Maps
# define cpresent(container, element) (find(all(container),element) != container.en()) // global find(): for Vectors. O(N) 


# define rep(i, n) for( ll (i) = 0; (i) < (n); (i)++)
# define repk(i,k,n) for( ll (i) = k; (i) < (n); (i)++)
# define REP(i, n) for( ll (i) = 1; (i) <= (n); (i)++)
# define wl(i) while((i)--)
# define sf(i) scanf("%lld",&(i))
# define pf(i) printf("%lld ",(i))
# define pfn(i) printf("%lld\n",(i))
# define csf(i) cin>>(i)
# define cpf(i) cout<<(i)<<" "
# define cpfn(i) cout<<(i)<<endl


# define MAX_PRIME 0
# define SEGMENT_MAX 100005
# define MOD 1000000007
# define sync_false std::ios_base::sync_with_stdio(false)
# define testcases() ll var;  cin>>var; while(var--)

const unsigned char option1 = 0x01; // hex for 0000 0001
const unsigned char option2 = 0x02; // hex for 0000 0010
const unsigned char option3 = 0x04; // hex for 0000 0100
const unsigned char option4 = 0x08; // hex for 0000 1000
const unsigned char option5 = 0x10; // hex for 0001 0000
const unsigned char option6 = 0x20; // hex for 0010 0000
const unsigned char option7 = 0x40; // hex for 0100 0000
const unsigned char option8 = 0x80; // hex for 1000 0000

using namespace std;

inline void Scan_f(long long *a)
{
    char c = 0;
    while(c<33)
        c = fgetc_unlocked(stdin);
    *a = 0;
    while(c>33){
        *a = (*a)*10 + c - '0';
        c = fgetc_unlocked(stdin);
    }
}

ll longestPalSubStr(string s)
{
    int n = s.size();

    bool table[n][n];
    memset(table, 0, sizeof(table));

    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        table[i][i] = true;

    int start = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (s[i] == s[i+1])
        {
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }

    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i < n-k+1 ; ++i)
        {
            int j = i + k - 1;
            if (table[i+1][j-1] && s[i] == s[j])
            {
                table[i][j] = true;

                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    return maxLength;
}

stack < ll > leaves;         // store the leaf nodes
map <ll , set< ll > > visitedBySource;
map< ll, vector< pair<ll,char> >  > adj_list;

ll bfs(ll s)            // return the longest palindromic path by calling longestPalSubStrinternally
{   
    queue <ll> nodes;
    bool visit[SEGMENT_MAX] = {false};
    map<ll,string> path;
    ll v, level = 0, lm = 0;
    nodes.push(s);
    while(!nodes.empty()){
        v = nodes.front(); nodes.pop(); visit[v] = true;
        if (v != s && adj_list[v].size() == 1)      // leaf node reached
        {
                if(!present(visitedBySource[s], v))
                {
                    lm = max(longestPalSubStr(path[v])+1,lm);              // local maxima
                    visitedBySource[v].insert(s);
                    visitedBySource[s].insert(v);                      // MEMOIZED
                    // DEBUG(path[v])
                    // DEBUG(lm)
                    // DEBUG(v)
                    // DEBUG(s)
                }
               

        }
        else
        {
            tr(adj_list[v], it){
                if(!visit[(*it).fs]){
                    visit[(*it).fs] = true;
                    nodes.push((*it).fs);
                    path[(*it).fs] = path[v] + (*it).se;      // COMPUTE THE CURRENT PATH
                }
            }
        }
    }

    return lm;

}

int main()
{   sync_false;
    string s;
    ll N, nc, v, u ,lf, lp = 0, p;
    char c;
    
    testcases(){
        lp = 0;
        Scan_f(&N); nc  = N-1;
        wl(nc){
            scanf("%lld %lld %c", &v,&u,&c);
            adj_list[v].pub( mp(u,c) );
            adj_list[u].pub( mp(v,c) );
        }
        tr(adj_list, it ){              // map< ll, vector< pair<ll,ll> >  >
            if ((it->se).size() == 1)        // IsLeaf?
            {
                leaves.push(it->fs);       // store Leaves
            }
        }

        while(!leaves.empty()){
            lf = leaves.top(); leaves.pop();
            p = bfs(lf);                // RUN BFS ON EACH LEAF AND COMPUTE THE REQD. PATH LENGTH
            lp = max(p, lp);
        }
        printf("%lld\n", lp);
        adj_list.cl();
        visitedBySource.cl();
    }
    

    return 0;
}