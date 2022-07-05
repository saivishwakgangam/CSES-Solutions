#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define for(i,n) for(ll i=0;i<(n);++i)
#define fora(i,a,n) for(ll i=a;i<=(n);++i)
#define forad(i,a,n) for(ll i=a;i>=(n);--i)
#define pb(v,temp) v.push_back(temp)

using namespace std;
using ll = long long;

void solve(ll num,ll sum)
{
    ll asum=((num)*(num+1))/2;
    cout<<asum-sum;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,temp;
    cin>>n;
    vector<ll>ele;
    ll sum=0;
    for(i,n-1){
        cin>>temp;
        pb(ele,temp);
    }
    for(i,n-1)
    {
        sum+=ele[i];
    }
    solve(n,sum);
    return 0;
}