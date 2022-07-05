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

void solve()
{
    ll n;
    cin>>n;
    map<ll,ll>pf;
    while(n%2==0){
        pf[2]++;
        n/=2;
    }
    for(ll div=3;div*div<=n;div+=2){
        while(n%div==0){
            pf[div]++;
            n/=div;
        }
    }
    if(n>1){
        pf[n]++;
    }
    ll res=0,exp;
    for(auto i:pf){
        exp=2*(i.second);
        ll first=1;
        ll last=floor(sqrt(exp));
        ll ans;
        while(first<=last){
            ll mid=(first+last)/2;
            if((mid*(mid+1))<=exp){
                ans=mid;
                first=mid+1;
            }
            else{
                last=mid-1;
            }
            
        }
        res+=ans;
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