#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define fori(i,n) for(ll i=0;i<(n);++i)
#define fora(i,a,n) for(ll i=a;i<=(n);++i)
#define forad(i,a,n) for(ll i=a;i>=(n);--i)
#define pb(v,temp) ll temp;cin>>temp;v.push_back(temp)

using namespace std;
using ll = long long;
const long long mod=1e9+7;
ll modular_expo(ll base,ll exp,ll m){
    ll res=1;
    while(exp){
        if(exp&1){
            res=(res*base)%m;
        }
        exp=exp/2;
        base=(base*base)%m;
    }
    return res;
}
void solve()
{
    ll a,b,c;
    cin>>a>>b>>c;
    ll y=modular_expo(b,c,mod-1);
    ll res=modular_expo(a,y,mod);
    cout<<res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
    
        solve();
        cout<<'\n';
    }
    return 0;
}