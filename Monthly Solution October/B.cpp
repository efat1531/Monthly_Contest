#include<bits/stdc++.h>
using namespace std;
typedef bool                      bol;
typedef int                       li;
typedef long long int             ll;
typedef unsigned long long int    l1;
typedef double                    db;
typedef string                    ST;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef vector < li >                   vli;
typedef vector < ll >                   vll;
typedef set < li >                      sli;
typedef set < ll >                      sll;
typedef pair < li, li >                pli;
typedef pair < ll, ll >                pll;
typedef map < li,li >                  mli;
typedef map < ll,ll >                  mll;
typedef unordered_map<ll,ll>           uml;
typedef vector < pair < li, li > >     vpi;
typedef vector < pair < ll, ll > >     vpl;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#define tcase                     int t;cin>>t;while(t--)
#define FORIN(arr,n)              for(ll i=0; i<n ;i++) cin>>arr[i]
#define FOR(n)                    for(ll i=0; i<n ;i++)
#define debug(arr,n)              for(ll i=0; i<n; i++) cout<<arr[i] << " "; newline;
#define faster                    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define input_txt                 freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define nl                        <<"\n"
#define sp                        <<" "<<
#define newline                   cout<<"\n"
#define outn(x)                   cout<<x nl;
#define out(x)                    cout<<x
#define yes                       cout<<"YES" nl
#define no                        cout<<"NO" nl
#define maxx_arr(ve)              *max_element(srt(ve))
#define minn_arr(ve)              *min_element(srt(ve))
#define lbound                    *lower_bound
#define ubound                    *upper_bound
#define len_s(u)                  ((int)u.size())
#define mem(b,z)                  memset(b,z,sizeof(b))
#define fixed(x)                  fixed<<setprecision(x)
#define srt(h)                    (h).begin(), (h).end()
#define lcm(a,b)                  (a*b)/__gcd(a,b);
#define sz                        size()

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void solves()
{
   ll n;
   cin>>n;
   ll a = n;
   ll d = n-1;
   ll b = n,c=2;

      for(ll i=1;i<=n;i++)
      {
        for(ll j=1;j<=n;j++)
        {
            if(j==1 ){
               out(char(i + 96));
            }
            else if(j==n )
            {
               out(char(a-- + 96));
            }
            else if(i==1 && c<=n-1)
            {
               out(char(c++ + 96));
               
            }
            else if(i==n)
            {
               out(char(d-- + 96));
            }
            else
            {
                out(" ");
            }
        }
        newline;
      }
}

void init_code()
{
    freopen("inputks.txt", "r", stdin);
    freopen("outputks.txt", "w", stdout);
}

int main()
{
    faster
    //tcase(solves());
    solves();
}