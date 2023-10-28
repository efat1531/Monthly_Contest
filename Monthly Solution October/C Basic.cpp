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
    int p[n], q[n];
    for(int i=0;i<n;i++)
    {
       cin>>p[i]>>q[i];
    }
    int tm=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(p[i]>p[j])
            {
                swap(p[i],p[j]);
                swap(q[i],q[j]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        int mq=min(c,q[i]);
        c-=mq;
        tm+=(p[i]*mq);
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