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
int fen[31][MaxN];

void fen_update(int indx, int bit, int val)
{
    if(indx==0)
        return;
    while(indx<MaxN)
    {
        fen[bit][indx]+=val;
        indx+=(indx&-indx);
    }
}

int fen_query(int indx, int bit)
{
    int sum=0;
    while(indx!=0)
    {
        sum+=fen[bit][indx];
        indx-=(indx&-indx);
    }
    return sum;
}

int query(int l, int r)
{
    int tn=r-l+1;
    int num=0;
    for(int i=0;i<31;i++)
    {
        int t1=fen_query(r,i)-fen_query(l-1,i);
        if(t1==tn)
            num+=pow(2,i);
    }
    return num;
}

void solve() {
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
        int temp=ar[i];
        for(int j=0;j<31;j++)
        {
            int val = temp%2;
            temp/=2;
            fen_update(i, j, val);
        }
    }

    
    while(q--)
    {
        int l, r, p;
        cin>>l>>r>>p;
        int ptemp=p;
        int mtemp=ar[l];
        cout<<query(l,r) nl;
        for(int i=0;i<31;i++)
        {
            int a=ptemp%2;
            int b=mtemp%2;
            if(b==1 and a==0)
                fen_update(l, i, -1);
            if(b==0 and a==1)
                fen_update(l, i, 1);
            ptemp/=2;
            mtemp/=2;
        }
        ar[l]=p;
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