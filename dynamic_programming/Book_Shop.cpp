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
    ll n,max_price,temp;
    cin>>n>>max_price;
    vector<ll>prices;
    vector<ll>pages;
    fori(i,n){
        cin>>temp;
        prices.push_back(temp);
    }
    fori(i,n){
        cin>>temp;
        pages.push_back(temp);
    }
    ll dp[2][max_price+1];
    memset(dp,0,sizeof(dp));
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<=max_price;j++){
            if(j==0){
                dp[1][j]=0;
            }
            else{
                if(prices[i-1]>j){
                    dp[1][j]=dp[0][j];
                }
                else{
                    dp[1][j]=max(pages[i-1]+dp[0][j-prices[i-1]],dp[0][j]);
                }
            }
        }
        for(ll j=0;j<=max_price;j++){
            dp[0][j]=dp[1][j];
        }
    }
    cout<<dp[1][max_price];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}