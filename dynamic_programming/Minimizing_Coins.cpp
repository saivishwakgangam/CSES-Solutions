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
    ll n,sum,temp;
    cin>>n>>sum;
    vector<ll>coins;
    fori(i,n){
        cin>>temp;
        coins.push_back(temp);
    }
    vector<ll>dp(sum+1,1e9);
    dp[0]=0;
    for(ll i=1;i<=sum;i++){
        for(ll j=0;j<n;j++){
            if((i-coins[j])>=0){
                dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
    }
    if(dp[sum]==1e9){
        cout<<"-1";
        return;
    }
    cout<<dp[sum];

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}