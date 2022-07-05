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

const ll inf=1e14+7;
void dijkstra(ll src_node,vector<pair<ll,ll>>adj_list[],vector<ll>&distance,vector<bool>&visited){
    priority_queue<pair<ll,ll>>q;
    distance[src_node]=0;
    q.push({0,1});
    while(!q.empty()){
        ll node=q.top().second;
        q.pop();
        if(visited[node]){
            continue;
        }
        visited[node]=true;
        for(auto i:adj_list[node]){
            if(distance[i.first]>distance[node]+i.second){
                distance[i.first]=distance[node]+i.second;
                q.push({-distance[i.first],i.first});
            }
        }
        

    }
}
void solve()
{
    //maintain a edge list
    ll n,m;
    cin>>n>>m;
    ll a,b,w;
    vector<pair<ll,ll>>adj_list[n+1];
    while(m--){
        cin>>a>>b>>w;
        adj_list[a].push_back({b,w});
    }
    vector<ll>distance(n+1,inf);
    vector<bool>visited(n+1,false);
    dijkstra(1,adj_list,distance,visited);
    for(ll i=1;i<=n;i++){
        cout<<distance[i]<<" ";
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