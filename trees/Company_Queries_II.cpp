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
ll l;
ll timer;
void dfs(ll node,ll parent,vector<ll>adj_list[],vector<vector<ll>>&up,vector<ll>&in_time,vector<ll>&out_time){
    in_time[node]=++timer;
    up[node][0]=parent;
    for(ll i=1;i<=l;i++){
        up[node][i]=up[up[node][i-1]][i-1];
    }
    for(auto child:adj_list[node]){
        if(child!=parent){
            dfs(child,node,adj_list,up,in_time,out_time);
        }
    }
    out_time[node]=++timer;

}
bool is_ancestor(ll node1,ll node2,vector<ll>&in_time,vector<ll>&out_time){
    return in_time[node1]<=in_time[node2]&&out_time[node1]>=out_time[node2];
}
void solve()
{
    ll n,q,temp;
    cin>>n>>q;
    vector<ll>adj_list[n+1];
    for(int i=2;i<=n;i++){
        cin>>temp;
        adj_list[temp].push_back(i);
        adj_list[i].push_back(temp);
        
    }
    //perform dfs and find ancestor in o(logn) time
    vector<ll>in_time(n+1,0);
    vector<ll>out_time(n+1,0);
     l=ceil(log2(n));
     timer=0;
    vector<vector<ll>>up(n+1,vector<ll>(l+1,0));
    dfs(1,1,adj_list,up,in_time,out_time);
    ll u,v;
    while(q--){
        cin>>u>>v;
        if(is_ancestor(u,v,in_time,out_time)){
            cout<<u<<endl;
            continue;
        }
        else if(is_ancestor(v,u,in_time,out_time)){
            cout<<v<<endl;
            continue;
        }
        for(ll i=l;i>=0;i--){
            if(!is_ancestor(up[u][i],v,in_time,out_time)){
                u=up[u][i];
            }
        }
        cout<<up[u][0]<<endl;
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