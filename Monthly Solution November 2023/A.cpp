#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long sum=0;
    long long nSum=((n+1)*n)/2;
    long long a;
    long long cnt=0;
    while(cin>>a)
    {
        sum+=a;
        cnt++;
    }
    cout<<n-cnt<<" "<<nSum-sum <<endl;
}