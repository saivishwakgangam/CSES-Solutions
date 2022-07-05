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
void solve()
{
    ll n;
    cin>>n;
    ll res=(((n%mod)*((n+3)%mod))-2)/2;
    map<ll,bool>mp;
    for(ll i=2;i*i<=n;i++){
        if(mp[i]==false){
            for(ll p=i;p<=n;p+=i){
                mp[p]=true;
                res=(res+((p%mod)*((n/p)-1)));
            }
        }
    }
    cout<<res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}