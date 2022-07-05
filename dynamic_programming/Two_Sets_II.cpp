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
ll max(ll a,ll b){
    if(a>b){
        return a;
    }
    return b;
}
void solve()
{
    ll n;
    cin>>n;
    ll sum=(n*(n+1))/2;
    if(sum%2){
        cout<<"0";
        return;
    }
    ll target=sum/2;
    bool dp[n+1][target+1];
    for(ll i=0;i<=n;i++){
        for(ll j=0;j<=target;j++){
            if(j==0){
                dp[i][j]=true;
            }
            else if(i==0){
                dp[i][j]=false;
            }
            else{
                if(j>=i){
                    dp[i][j]=dp[i-1][j-i]||dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    if(!dp[n][target]){
        cout<<"0";
        return;
    }
    queue<pair<ll,ll>>window;
    pair<ll,ll>index;
    ll i,j;
    ll res=INT_MIN;
    window.push(make_pair(n,target));
   

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}