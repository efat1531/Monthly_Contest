// Problem Link - https://codeforces.com/problemset/problem/1850/F

#include <bits/stdc++.h>
using namespace std;

#define nl << "\n"

void solve() {
    int t;
    cin>>t;
    while(t--)
    {
	int n;
	cin>>n;
	map<int,int>mp;
	int cnt[n+5]={0};
	for(int i=0;i<n;i++)
	{
	    int a;
	    cin>>a;
	    mp[a]++;
	}
	int maxNum=0;
	for(auto x:mp)
	{
	    int jump=x.first;
	    int frog=x.second;
	    for(int i=jump;i<n+1;i+=jump)
	    {
		cnt[i]+=frog;
		maxNum=max(maxNum,cnt[i]);
	    }
	}
	cout<<maxNum nl;
    }
}

int32_t main() {
  solve();
  return 0;
}