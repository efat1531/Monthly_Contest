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

void solve()
{
    int n;
    cin>>n;
    int c;
    cin>>c;
    pair<int,  int>fruit[n];
    for(int i=0;i<n;i++)
    {
        ll p,q;
        cin>>p>>q;
        fruit[i]={p,q};
    }
    int tm=0;
    sort(fruit,fruit+n);
    for(int i=0;i<n;i++)
    {
        int mq=min(c,fruit[i].second);
        c-=mq;
        tm+=(mq*fruit[i].first);
        if(c==0)
            break;
    }
    cout<<tm nl;
}

int32_t main()
{
    fast_io;
    solve();
    return 0;
}