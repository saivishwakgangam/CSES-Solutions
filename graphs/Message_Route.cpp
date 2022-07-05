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
ll final_distance;
string path;
bool flag;
void bfs(ll src_node,ll end_node,vector<ll>adj_list[],vector<ll>&distance,vector<ll>&visited){
    queue<pair<ll,string>>q;
    q.push({src_node,to_string(src_node)});
    distance[src_node]=0;
    visited[src_node]=true;
    while(!q.empty()){
        pair<ll,string>temp;
        temp=q.front();
        q.pop();
        for(auto adj_nodes:adj_list[temp.first]){
            if(adj_nodes==end_node){
                flag=true;
                final_distance=distance[temp.first]+1;
                path=temp.second+" "+to_string(adj_nodes);
                return;
            }
            if(visited[adj_nodes]){
                continue;
            }
            visited[adj_nodes]=true;
            distance[adj_nodes]=1+distance[temp.first];
            string t=temp.second+" "+to_string(adj_nodes);
            q.push({adj_nodes,t});
        }
    }
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    vector<ll>adj_list[n+1];
    ll a,b;
    while(m--){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    vector<ll>distance(n+1,0);
    vector<ll>visited(n+1,false);
    bfs(1,n,adj_list,distance,visited);
    if(flag){
        cout<<final_distance+1<<'\n';
        cout<<path;
    }
    else{
        cout<<"IMPOSSIBLE";
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