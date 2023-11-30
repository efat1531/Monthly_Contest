#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string a,b;
        cin>>a>>b;
        if(a.size()<b.size()){
            swap(a,b);
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        while(a.size()>b.size()){
            b.push_back('0');
        }
        // cout<<a<<" "<<b<<endl;
        string ans;
        int i,j,carry=0;
        for(i=0; i<a.size(); i++){
            int cal = a[i]+b[i]-48*2+carry;
            carry = cal/10;
            cal%=10;
            ans += (cal+'0');
        }
        if(carry)ans+=(carry+'0');
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
}