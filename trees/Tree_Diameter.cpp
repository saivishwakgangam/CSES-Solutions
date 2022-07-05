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

void dfs(ll node,ll parent,vector<ll>adj_list[],vector<ll>&max_path,vector<ll>&toleaf){
    multiset<ll>s;
    for(ll adj_nodes:adj_list[node]){
        if(adj_nodes==parent)continue;
        dfs(adj_nodes,node,adj_list,max_path,toleaf);
        toleaf[node]=max(toleaf[node],1+toleaf[adj_nodes]);
        s.insert(toleaf[adj_nodes]);
    }
    if(s.size()>0){
        if(s.size()==1){
            auto it=s.begin();
            max_path[node]=1+*it;
        }
        else{
            auto it=s.rbegin();
            ll max1=*it;
            it--;
            ll max2=*it;
            max_path[node]=2+max1+max2;
        }
    }
    
}
void solve()
{
    ll n,m,a,b;
    cin>>n;
    m=n-1;
    vector<ll>adj_list[n+1];
    while(m--){
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    vector<ll>max_path(n+1,0);
    vector<ll>toleaf(n+1,0);
    dfs(1,-1,adj_list,max_path,toleaf);
    ll res=0;
    for(auto i:max_path){
        res=max(res,i);
    }
    cout<<res;
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}