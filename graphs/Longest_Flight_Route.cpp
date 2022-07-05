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
void kahn(ll n,vector<ll>forward_edge[],vector<ll>backward_edge[],vector<ll>&indegree,vector<pair<ll,vector<ll>>>&max_paths){
    queue<ll>q;
    vector<ll>temp;
    for(ll i=1;i<=n;i++){
        if(!indegree[i]){
            q.push(i);
            temp.clear();
            temp.push_back(i);
            max_paths[i]={1,temp};
        }
    }
    ll node;
    while(!q.empty()){
        node=q.front();
        q.pop();
        for(auto adj_nodes:forward_edge[node]){
            indegree[adj_nodes]--;
            if(!indegree[adj_nodes]){
                q.push(adj_nodes);
            }
        }
        //backedge
        for(auto prev:backward_edge[node]){
            max_paths[node]=

        }

    }
}
void solve()
{
    ll n,m,a,b;
    cin>>n>>m;
    vector<ll>forward_edge[n+1];
    vector<ll>backward_edge[n+1];
    vector<pair<ll,vector<ll>>>max_paths;
    vector<ll>indegree(n+1,0);
    while(m--){
        cin>>a>>b;
        indegree[b]++;
        forward_edge[a].push_back(b);
        backward_edge[b].push_back(a);
    }
    kahn(n,forward_edge,backward_edge,indegree,max_paths);
    cout<<max_paths[n].first<<'\n';
    for(auto i:max_paths[n].second){
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