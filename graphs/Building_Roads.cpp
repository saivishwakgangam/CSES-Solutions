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

void dfs(ll node,vector<ll>adj_list[],vector<bool>&visited){
    if(visited[node]){
        return;
    }
    visited[node]=true;
    for(auto adj_nodes:adj_list[node]){
        
            dfs(adj_nodes,adj_list,visited);
    }
}
void solve()
{
    ll n,m,a,b;
    cin>>n>>m;
    vector<ll>adj_list[n+1];
    while(m--){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    vector<bool>visited(n+1,false);
    vector<ll>result;
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            result.push_back(i);
            dfs(i,adj_list,visited);
        }
    }
    cout<<result.size()-1<<'\n';
    for(ll i=0;i<result.size()-1;i++){
        cout<<result[i]<<" "<<result[i+1]<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}