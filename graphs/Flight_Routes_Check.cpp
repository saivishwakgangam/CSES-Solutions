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
vector<vector<ll>>res;
void dfs(ll node,vector<ll>adj_list[],vector<bool>&visited,stack<ll>&s){
    visited[node]=true;
    for(auto adj_nodes:adj_list[node]){
        if(!visited[adj_nodes]){
            dfs(adj_nodes,adj_list,visited,s);
        }
    }
    s.push(node);
}
void new_dfs(ll node,vector<ll>adj_list[],vector<bool>&visited,vector<ll>&temp){
    visited[node]=true;
    temp.push_back(node);
    for(auto adj_nodes:adj_list[node]){
        if(!visited[adj_nodes]){
            new_dfs(adj_nodes,adj_list,visited,temp);
        }
    }
}
void kosaraju(vector<ll>adj_list[],vector<ll>adj_list_rev[],ll n){
    stack<ll>s;
    vector<bool>visited(n+1,false);
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i,adj_list,visited,s);
        }
    }
    //now do dfs on transpose of graph
    std::fill(visited.begin(),visited.end(),false);
    vector<ll>temp;
    stack<ll>temp_stack=s;
    while(!s.empty()){
        if(!visited[s.top()]){
           temp.clear();
           new_dfs(s.top(),adj_list_rev,visited,temp);  
           res.push_back(temp);
        }
        s.pop();
    }



    
}
bool dfs_path(ll a,ll b,vector<ll>adj_list[],vector<bool>&visit){
   if(a==b){
       return true;
   }
   visit[a]=true;
   bool res=false;
   for(ll adj_nodes:adj_list[a]){
       if(!visit[adj_nodes]){
           res=res||dfs_path(adj_nodes,b,adj_list,visit);
        
       }
   }
   return res;
}
void solve()
{
    ll n,m,a,b;
    cin>>n>>m;
    vector<ll>adj_list[n+1];
    vector<ll>adj_list_rev[n+1];
    while(m--){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list_rev[b].push_back(a);
    }
    kosaraju(adj_list,adj_list_rev,n);
    if(res.size()==1){
        cout<<"YES";
    }
    else{
       cout<<"NO"<<'\n';
       ll a=res[0][0];
       ll b=res[1][0];
       vector<bool>visit(n+1,false);
       if(dfs_path(a,b,adj_list,visit)){
           cout<<b<<" "<<a;
       }
       else{
           cout<<a<<" "<<b;
       }
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