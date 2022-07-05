#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define fori(i,n) for(ll i=0;i<(n);++i)
#define fora(i,a,n) for(ll i=a;i<=(n);++i)
#define forad(i,a,n) for(ll i=a;i>=(n);--i)
#define pb(v) ll temp;cin>>temp;v.push_back(temp)

using namespace std;
using ll = long long;

void solve()
{
    ll n;
    cin>>n;
    if(n==1){
        cout<<"0";
        return;
    }
    vector<ll>ele;
    fori(i,n){
        pb(ele);
    }
    ll ans=0;
    for(ll i=1;i<n;i++){
        if(ele[i-1]>ele[i]){
            ans+=(ele[i-1]-ele[i]);
            ele[i]=ele[i-1];
        }
    }
    cout<<ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}