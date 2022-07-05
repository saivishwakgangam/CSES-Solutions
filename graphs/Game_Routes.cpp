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
const ll mod=1e9+7;
void kahn(ll n,vector<ll>adj_list[],vector<ll>backedge[],vector<ll>&paths,vector<ll>&indegree){
    queue<ll>q;
    for(ll i=1;i<=n;i++){
        if(!indegree[i]){
            q.push(i);
        }
    }
    paths[1]=1;
    ll temp;
    while(!q.empty()){
        temp=q.front();q.pop();
        for(ll adj_nodes:adj_list[temp]){
            indegree[adj_nodes]--;
            if(!indegree[adj_nodes]){
                q.push(adj_nodes);
            }
        }
        for(ll prev:backedge[temp]){
            paths[temp]=(paths[temp]+paths[prev])%mod;
        }
    }
}
void solve()
{
    ll n,m,a,b;
    cin>>n>>m;
    vector<ll>adj_list[n+1];
    vector<ll>backedge[n+1];
    vector<ll>paths(n+1,0);
    vector<ll>indegree(n+1,0);
    while(m--){
        cin>>a>>b;
        adj_list[a].push_back(b);
        backedge[b].push_back(a);
        indegree[b]++;
    }
    kahn(n,adj_list,backedge,paths,indegree);
    cout<<paths[n]%mod;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}