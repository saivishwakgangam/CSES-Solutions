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
void dfs(ll i,vector<ll>forward_edge[],vector<bool>&visited,stack<ll>&st){
   visited[i]=true;
   for(auto adj_nodes:forward_edge[i]){
       if(!visited[adj_nodes]){
           dfs(adj_nodes,forward_edge,visited,st);
       }
   }
   st.push(i);
}
void new_dfs(ll node,vector<ll>reverse_edge[],vector<bool>&visited,vector<ll>&temp){
    visited[node]=true;
    temp.push_back(node);
    for(auto adj_nodes:reverse_edge[node]){
        if(!visited[adj_nodes]){
            new_dfs(adj_nodes,reverse_edge,visited,temp);
        }
    }
}
void kahn(ll n,vector<ll>new_graph[],vector<ll>backedge[],vector<ll>&indegree,vector<ll>&max_coin,map<ll,ll>&coin_sum){
    queue<ll>q;
    for(ll i=1;i<=n;i++){
        if(!indegree[i]){
            q.push(i);
        }
    }
    ll node;
    while(!q.empty()){
        node=q.front();q.pop();
        for(ll adj_nodes:new_graph[node]){
            indegree[adj_nodes]--;
            if(!indegree[adj_nodes]){
                q.push(adj_nodes);
            }
        }
        for(ll prev:backedge[node]){
           max_coin[node]=max(max_coin[node],max_coin[prev]);
        }
        max_coin[node]+=coin_sum[node];
    }
}
void kosaraju(ll n,vector<ll>forward_edge[],vector<ll>reverse_edge[],vector<ll>&coin_values){
    stack<ll>st;
    vector<bool>visited(n+1,false);
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,forward_edge,visited,st);
        }
    }
    vector<ll>temp;
    vector<vector<ll>>res;
    std::fill(visited.begin(),visited.end(),false);
    while(!st.empty()){
        if(!visited[st.top()]){
            temp.clear();
            new_dfs(st.top(),reverse_edge,visited,temp);
            res.push_back(temp);
        }
        st.pop();
    }
    //modifying graph

    map<ll,ll>node_scc;
    map<ll,ll>coin_sum;
    for(ll i=0;i<res.size();i++){
        ll sum=0;
        for(auto temp:res[i]){
            sum+=coin_values[temp-1];
            node_scc[temp]=i+1;
        }
        coin_sum[i+1]=sum;
    }
    vector<ll>new_graph[res.size()+1];
    vector<ll>backedge[res.size()+1];
    vector<ll>indegree(res.size()+1,0);
    ll n_scc,a_scc;
    for(ll i=1;i<=n;i++){
        n_scc=node_scc[i];
        for(auto j:forward_edge[i]){
            a_scc=node_scc[j];
            if(n_scc!=a_scc){
                new_graph[n_scc].push_back(a_scc);
                backedge[a_scc].push_back(n_scc);
                indegree[a_scc]++;
            }
        }
    }
    //now applying kahn algorithm to get max coin collection
    vector<ll>max_coin(res.size()+1,0);
    kahn(res.size(),new_graph,backedge,indegree,max_coin,coin_sum);
    ll result=INT_MIN;
    for(ll i:max_coin){
        if(i>result){
            result=i;
        }
       
    }
    cout<<result;

}
void solve()
{
    ll n,m,temp,a,b;
    cin>>n>>m;
    vector<ll>coin_values;
    for(ll i=0;i<n;i++){
        cin>>temp;
        coin_values.push_back(temp);
    }
    vector<ll>forward_edge[n+1],reverse_edge[n+1];
    while(m--){
        cin>>a>>b;
        forward_edge[a].push_back(b);
        reverse_edge[b].push_back(a);
    }
    // apply kosaraju algorithm to get the scores
    kosaraju(n,forward_edge,reverse_edge,coin_values);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}