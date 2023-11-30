#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define nl << "\n"

vector<int>v;

bool canEat(ll k, ll b)
{
    for(int i=0;i<v.size();i++)
    {
        ll a= (v[i]+k-1)/k;
        b-=a;
    }
    if(b>=0)
        return true;
    return false;
}


void solve() {
   
    
        ll n,hour;
        cin>>n>>hour;
        ll k=0;
        for(int i=0;i<n;i++)
        {
            ll a;
            cin>>a;
            v.push_back(a);
            k=max(a,k);
        }
        ll l=1,h=k;
        while(l<=h)
        {
            ll mid=(l+h)/2;
            if(canEat(mid, hour))
            {
                k=mid;
                h=mid-1;
            }else
            {
                l=mid+1;
            }
        }
        cout<<k nl;
        v.clear();
    
}
 
int32_t main() {
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}