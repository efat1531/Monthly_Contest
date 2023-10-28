// Hint: Don't look, No need, Let'em Play.

#pragma optimize("O2")
#include "bits/stdc++.h"
#include <bits/stdc++.h>

using namespace std;

//#define int long long
typedef unsigned long long l1;
#define nl << "\n"
#define fast                                                                   \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);                                                                  \
  cout.tie(0);

#ifndef bhupixb
#define var(...)
#define stl(...)
#endif

typedef long long ll;

#define testcase(t, x)                                                         \
  int t;                                                                       \
  cin >> t;                                                                    \
  for (int x = 1; x <= t; x++)

const int MaxN=1e5+5;
int ar[MaxN];
int tree[4*MaxN];


void build(int node, int s, int e)
{
    if(s==e)
    {
	tree[node]=ar[s];
	return;
    }
    int mid = (s+e)/2;
    int left = 2*node;
    int right = 2*node+1;
    build(left, s, mid);
    build(right, mid+1, e);
    
    tree[node]= tree[left]&tree[right];
}

ll query(int node, int b, int e, int l, int r) 
{
	if(b >= l and e <= r) return tree[node];
	if(e < l or b > r) return INT_MAX;
	
	int mid = (b + e) / 2;
	int left = 2 * node;
	int right = 2 * node + 1;
	
	return (query(left, b, mid, l, r) & query(right, mid + 1, e, l, r));
}

void update(int node, int s, int e, int l, int value)
{
	if(s == l and e == l) {
		tree[node]=value;
		return;
	}
	if(s > l or e < l) return;
	int mid = (s + e) / 2;
	int left = 2 * node;
	int right = 2 * node + 1;
	
	update(left, s, mid, l, value);
	update(right, mid + 1, e, l, value);
	tree[node]= tree[left]&tree[right];

}

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
	cin>>ar[i];
    build(1,1,n);
    
    while(q--)
    {
	int l, r, p;
	cin>>l>>r>>p;
	cout<<query(1,1,n,l,r) nl;
	update(1,1,n,l,p);
    }
}



signed main() {
  fast;
  srand(time(0));
  int t = 1;
  //cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}