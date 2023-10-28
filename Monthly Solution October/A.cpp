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

const int maxN = 1e5+6;
ll ar[maxN];
int n;
ll pn=0;

bool check(int t)
{
    int tp=0;
    for(int i=1;i<=n;i++)
    {
        if(ar[i]>t)
            break;
        tp+=(t/ar[i]);
        if(tp>=pn)
            break;
    }
    if(tp>=pn)
        return true;
    else return false;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    sort(ar+1, ar+n);
    cin>>pn;
    ll l=0,h=1e17;
    int ans=0;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(check(mid))
        {
            ans=mid;
            h=mid-1;
        }else
            l=mid+1;
    }
    cout<<ans nl;
}

int32_t main()
{
    fast_io;
    solve();
    return 0;
}