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
void dfs(ll node,ll parent,vector<ll>adj_list[],vector<pair<ll,ll>>&dp){
    ll sum;
    for(auto child:adj_list[node]){
        if(child!=parent){
            dfs(child,node,adj_list,dp);
            dp[node].second+=dp[child].first;
        }
    }
    sum=dp[node].second;
    ll temp;
    for(auto child:adj_list[node]){
        temp=sum;
        if(child!=parent){
            temp-=dp[child].first;
            dp[node].first=max(dp[node].first,1+dp[child].second+temp);
        }
        
        
    }
   

}
void solve()
{
    ll n,m,a,b;
    cin>>n;
    vector<ll>adj_list[n+1];
    m=n-1;
    while(m--){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    vector<pair<ll,ll>>dp(n+1,{0,0});
    dfs(1,-1,adj_list,dp);
    cout<<dp[1].first;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}