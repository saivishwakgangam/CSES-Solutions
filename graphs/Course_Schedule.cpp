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
vector<ll>res;
void bfs(ll n,vector<ll>adj_list[],vector<ll>&indegree,vector<bool>&visited){
    queue<ll>q;
    for(ll i=1;i<=n;i++){
        if(!indegree[i]){
            visited[i]=true;
            q.push(i);
        }
    }
    ll node;
    while(!q.empty()){
        node=q.front();q.pop();
        res.push_back(node);
        for(auto adj_nodes:adj_list[node]){
            indegree[adj_nodes]--;
            if(!indegree[adj_nodes]){
                visited[adj_nodes]=true;
                q.push(adj_nodes);
            }
        }
    }
}
void kahn(ll n,vector<ll>adj_list[],vector<ll>&indegree){
    vector<bool>visited(n+1,0);
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            bfs(n,adj_list,indegree,visited);
        }
    }
}
void solve()
{
    ll n,m,a,b;
    cin>>n>>m;
    vector<ll>adj_list[n+1];
    vector<ll>indegree(n+1,0);
    while(m--){
        cin>>a>>b;
        adj_list[a].push_back(b);
        indegree[b]++;
    }
    kahn(n,adj_list,indegree);
    if(res.size()!=n){
        cout<<"IMPOSSIBLE";
        return;
    }
    for(auto i:res){
        cout<<i<<" ";
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