#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define nl << "\n"

const int MaxN=1e5+5;
int s_node,e_node;
vector<int>primes;
vector<int>Connect[MaxN];
int level[MaxN];
int parent[MaxN];

bool is_prime(int num)
{
    for(int i=2;i*i<=num;i++){
	    if(num%i==0){
	        return false;
	    }
    }
    return true;
}

void prime_gen()
{
    for(int i=1001;i<10000;i+=2)
    {
	    if(is_prime(i))
	        primes.push_back(i);
    }
}

bool valid(int a,int b)
{
    int cnt=0;
    while(a>0)
    {
	    if(a%10!=b%10)
	        cnt++;
	    a/=10,b/=10;
    }
    if(cnt==1)
	    return true;
    else
	    return false;
}

void Graph_Build()
{
    prime_gen();
    int v_size=primes.size();
    for(int i=0;i<v_size;i++)
    {
	    for(int j=i+1;j<v_size;j++)
	    {
	        if(valid(primes[i],primes[j]))
	        {
		        int u=primes[i];
		        int v=primes[j];
		        Connect[u].push_back(v);
		        Connect[v].push_back(u);
	        }
	    }
    }
}

void bfs(int source)
{
    memset(level,-1,sizeof level);
    level[source]=0;
    queue<int>q;
    q.push(source);
    parent[source]=0;
    while(!q.empty())
    {
	int par=q.front();
	q.pop();
	for(auto i:Connect[par])
	{
	    if(level[i]==-1)
	    {
		parent[i]=par;
		level[i]=level[par]+1;
		if(i==e_node)
		    return;
		q.push(i);
	    }
	}
    }
}
 
void solve() {
    Graph_Build();
        int t;
        cin>>t;
        while(t--){
	    cin>>s_node>>e_node;
	    bfs(s_node);
	    if(level[e_node]==-1)
	        cout<<"Impossible" nl;
	    else
	        cout<<level[e_node] nl;
    }
}
 
int32_t main() {
  solve();
  return 0;
}
