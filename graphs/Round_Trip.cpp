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

bool final_flag=false;
void dfs(ll node,vector<ll>adj_list[],vector<bool>&visited,vector<ll>&path,ll parent){
    for(auto adj_nodes:adj_list[node])
    {
        if(!final_flag){
            if(visited[adj_nodes]){
                if(adj_nodes!=parent){
                    final_flag=true;
                    vector<ll>res;
                    res.push_back(adj_nodes);
                    for(ll i=path.size()-1;i>=0;i--){
                        res.push_back(path[i]);
                        if(path[i]==adj_nodes){
                            break;
                        }
                    }
                    cout<<res.size()<<'\n';
                    reverse(res.begin(),res.end());
                    for(auto i:res){
                        cout<<i<<" ";
                    }
                    
                    return;
                }
            }
            else{
                visited[adj_nodes]=true;
                path.push_back(adj_nodes);
                dfs(adj_nodes,adj_list,visited,path,node);

            }
        }
    }
    path.pop_back();
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    ll a,b;
    vector<ll>adj_list[n+1];
    while(m--){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    vector<bool>visited(n+1,false);
    vector<ll>path;
    for(ll i=1;i<=n;i++){
        if(!visited[i]){
            path.clear();
            path.push_back(i);
            visited[i]=true;
            dfs(i,adj_list,visited,path,-1);
            if(final_flag){
                return;
            }
            
        }
    }
    cout<<"IMPOSSIBLE";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}