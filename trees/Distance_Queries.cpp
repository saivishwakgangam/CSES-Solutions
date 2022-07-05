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
ll timer;
void dfs(ll node,ll parent,ll size,vector<ll>adj_list[],vector<vector<ll>>&up,vector<ll>&in_time,vector<ll>&out_time,vector<ll>&height,ll h){
    in_time[node]=++timer;
    height[node]=h;
    up[node][0]=parent;
    for(ll i=1;i<=size;i++){
        up[node][i]=up[up[node][i-1]][i-1];
    }
    for(auto child:adj_list[node]){
        if(child!=parent){
            dfs(child,node,size,adj_list,up,in_time,out_time,height,h+1);
        }
    }
    out_time[node]=++timer;
}
bool is_ancestor(ll u,ll v,vector<ll>&in_time,vector<ll>&out_time){
    return in_time[v]>=in_time[u]&&out_time[u]>=out_time[v];
}
void solve()
{
    ll n,q,a,b;
    cin>>n>>q;
    ll m=n-1;
    vector<ll>adj_list[n+1];
    while(m--){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    //construct dfs and store in_time,out_time and height of the node from the root and binary uplifting
    ll size=ceil(log2(n));
    vector<ll>in_time(n+1,0);
    vector<ll>out_time(n+1,0);
    vector<ll>height(n+1,0);
    vector<vector<ll>>up(n+1,vector<ll>(size+1,0));
    timer=0;
    dfs(1,1,size,adj_list,up,in_time,out_time,height,0);
    ll lca;
    
    while(q--){
        cin>>a>>b;
        ll temp_a=a;
        if(is_ancestor(a,b,in_time,out_time)){
            lca=a;
        }
        else if(is_ancestor(b,a,in_time,out_time)){
            lca=b;
        }
        else{
            //perform binary uplifitng
            for(ll i=size;i>=0;i--){
                if(!is_ancestor(up[a][i],b,in_time,out_time)){
                    a=up[a][i];
                }
            }
            lca=up[a][0];
        }
      
        ll res=height[temp_a]+height[b]-2*height[lca];
        cout<<res<<'\n';
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