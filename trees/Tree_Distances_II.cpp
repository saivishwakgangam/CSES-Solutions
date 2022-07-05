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

void dfs(ll node,ll parent,vector<ll>&subtree,vector<ll>&distance,vector<ll>adj_list[]){
    for(auto child:adj_list[node]){
        if(child==parent)continue;
        dfs(child,node,subtree,distance,adj_list);
        distance[node]+=(subtree[child]+distance[child]);
        subtree[node]+=subtree[child];
    }
}
void reroot(ll node,ll parent,ll n,vector<ll>&subtree,vector<ll>&distance,vector<ll>adj_list[],vector<ll>&res){
    if(parent==-1){
        res[node]=distance[1];
    }
    else{
        res[node]=res[parent]-(distance[node]+subtree[node])+(n-subtree[node])+distance[node];
    }
    for(auto child:adj_list[node]){
        if(child!=parent){
            reroot(child,node,n,subtree,distance,adj_list,res);
        }
    }
}
void solve()
{
    ll n,m,a,b;
    cin>>n;
    m=n-1;
    vector<ll>adj_list[n+1];
    while(m--){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    vector<ll>subtree(n+1,1);
    vector<ll>distance(n+1,0);
    dfs(1,-1,subtree,distance,adj_list);
    vector<ll>res(n+1,0);
    
    //reerooting concept
    reroot(1,-1,n,subtree,distance,adj_list,res);
    for(ll i=1;i<=n;i++){
        cout<<res[i]<<" ";
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