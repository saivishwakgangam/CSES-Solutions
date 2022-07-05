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
ll edges=0;
ll min_weight=0;
ll find(ll node,vector<ll>&parent){
    if(parent[node]==-1){
        return node;
    }
    return (parent[node]=find(parent[node],parent));
}
void kruskal(ll n,vector<pair<ll,pair<ll,ll>>>&edge_list){
    vector<ll>parent(n+1,-1);
    vector<ll>rank(n+1,0);
    ll node1,node2,abs_r1,abs_r2,weight;
    for(auto e:edge_list){
        weight=e.first;
        node1=e.second.first;
        node2=e.second.second;
        abs_r1=find(node1,parent);
        abs_r2=find(node2,parent);
        if(abs_r1!=abs_r2){
            edges++;
            min_weight+=weight;
            if(rank[abs_r1]==rank[abs_r2]){
                rank[abs_r2]++;
                parent[abs_r1]=abs_r2;
            }
            else if(rank[abs_r1]>rank[abs_r2]){
                parent[abs_r2]=abs_r1;
            }
            else{
                parent[abs_r1]=abs_r2;
            }
        }

    }
}
void solve()
{
    ll n,m,a,b,w;
    cin>>n>>m;
    vector<pair<ll,pair<ll,ll>>>edge_list;
    while(m--){
        cin>>a>>b>>w;
        edge_list.push_back({w,{a,b}});
    }
    sort(edge_list.begin(),edge_list.end());
    kruskal(n,edge_list);
    if(edges==n-1){
        cout<<min_weight;
        return;
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