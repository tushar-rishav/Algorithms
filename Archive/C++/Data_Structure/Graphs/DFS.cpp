/*
	Recursive and Iterative implementation of Depth First Search for Graphs
*/
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

const unsigned char option1 = 0x01; // hex for 0000 0001
const unsigned char option2 = 0x02; // hex for 0000 0010
const unsigned char option3 = 0x04; // hex for 0000 0100
const unsigned char option4 = 0x08; // hex for 0000 1000
const unsigned char option5 = 0x10; // hex for 0001 0000
const unsigned char option6 = 0x20; // hex for 0010 0000
const unsigned char option7 = 0x40; // hex for 0100 0000
const unsigned char option8 = 0x80; // hex for 1000 0000

using namespace std;

struct node{
	ll data;
	ll pos;
};
vector< node > nodes;
bool visited_r[100] = {false};
bool visited_i[100] = {false};
vvll adj_list(100);	// Space complexity O(nodes + edges)
ll nod;

void dfs_recursive(ll);
void dfs_iterative(ll);	
void print_graph();

int main()
{  
	sync_false;
	ll edges,ec,x,y,nc;
	
	csf(nod);
	csf(edges);
	
	node n;
	nc = nod;
	
	n.data = 0;
	n.pos = 0;
	nodes.pub(n);	// start counting from 1 by keeping garbage value at 0. Just for convenience
	cpfn("Provide node position,data");
	wl(nc){
		csf(x);csf(y);	// index,data
		n.data = y;
		n.pos = x;
		nodes.pub(n);
	}
	cpfn("Provide adjacent nodes for each node");
	ec = edges;
	wl(ec){
		csf(x);csf(y);
		adj_list[x].pub(y);
	}

	print_graph();
	cpfn("Iterative approach..");
	dfs_iterative();
	cpfn("\nRecursive approach..");
	dfs_recursive(1);
	/*
		NOTE: each dfs traversal counts one connected components. 
		So in a graph of N dfs means N connected components total
	*/

	return 0;
}
void dfs_recursive(ll s)
{
	visited_r[s] = true;
	cpf(nodes[s].data);
	tr(adj_list[s],it){	// adj_list[s] gives all the adjacent nodes of s
		if(!visited_r[*it])
			dfs_recursive(*it);
	}

}

void dfs_iterative(ll s)
{
	stack <ll> S;			// S contains list of all unvisited children nodes
	visited_i[s] = true;
	S.push(s); ll v;
	
	while(!S.empty()){
		v = S.top();S.pop();
		cpf(nodes[v].data);	// process the node
		tr(adj_list[v],it){
			if(!visited_i[*it]){
				visited_i[*it] = true;	// push the node and mark it visited
				S.push(*it);
			}
		}		
	}
	
}

void print_graph()
{
	cpfn("The graph is");
	REP(i,nod){
		cpf(i);cpf("{");cpf(nodes[i].data);cpf("} ");cpf("->");
		bool flag = true;
		tr(adj_list[i],it){
			if(flag){
				flag = false;
			}
			if(it==adj_list[i].en()-1){
				cpf(*it);
				cpf("{");cpf(nodes[*it].data);cpf("} ");
				cout<<endl;
			}else{
				cpf(*it);cpf("{");cpf(nodes[*it].data);cpf("} ");cpf(",");
			}
		}
		if(flag)
			cpfn("null");
		
	}
}
