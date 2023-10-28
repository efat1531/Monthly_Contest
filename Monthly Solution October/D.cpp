#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long l1;
typedef double db;
#define pi 2 * acos(0.0)
#define sz(x) (x).size()
#define read(x) \
    int x;      \
    cin >> x
#define prDouble(x, y) fixed << setprecision(y) << x
#define lcm(a, b) (a * b) / __gcd(a, b);
#define sortof(x) sort((x).begin(), (x).end());
#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define mm(x, v) memset((x), v, sizeof(x));
#define testcase(t, x) \
    int t;             \
    cin >> t;          \
    for (int x = 1; x <= t; x++)
#define nl << "\n"

const int maxN=1e5+6;
vector<int>graph[maxN];
int n;
int ex, sp, mp;

int pl[maxN];
int mon[maxN];

void bfs_mon(int s)
{
    mon[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int par = q.front();
        q.pop();
        for(auto x:graph[par])
        {
            if(mon[x]==-1)
            {
                mon[x]=mon[par]+1;
                q.push(x);
            }
        }
    }

}

void bfs_pl(int s)
{
    pl[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int par=q.front();
        q.pop();
        for(auto x:graph[par])
        {
            int t=pl[par]+1;
            if((mon[x]>t or mon[x]==-1) and pl[x]==-1)
            {
                q.push(x);
                pl[x]=t;
            }
        }
    }
}

void solve()
{
    int m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(pl, -1, sizeof pl);
    memset(mon, -1, sizeof mon);
    cin>>ex;
    cin>>mp>>sp;
    bfs_mon(mp);
    bfs_pl(sp);
    if(pl[ex]!=-1)
        cout<<"Yes, I will with this game!" nl;
    else
        cout<<"Nooo. I failed this time, but I will not fail next time." nl;

}

int32_t main()
{
    fast_io;
    solve();
    return 0;
}