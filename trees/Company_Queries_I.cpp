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
void dfs(ll node,ll parent,vector<ll>adj_list[],vector<vector<ll>>&up,ll size){
    up[node][0]=parent;
    for(ll i=1;i<=size;i++){
        if(up[node][i-1]==-1){
            break;
        }
        up[node][i]=up[up[node][i-1]][i-1];
    }
    for(auto child:adj_list[node]){
        if(child==parent){
            continue;
        }
        dfs(child,node,adj_list,up,size);
    }

}
void solve()
{
    ll n,q,temp;
    cin>>n>>q;
    vector<ll>adj_list[n+1];
    for(ll i=2;i<=n;i++){
        cin>>temp;
        adj_list[i].push_back(temp);
        adj_list[temp].push_back(i);
    }
    ll size=ceil(log2(n));
    vector<vector<ll>>up(n+1,vector<ll>(size+1,-1));
    dfs(1,-1,adj_list,up,size);
    ll node,k;
    while(q--){
        cin>>node>>k;
        ll base,u;
        u=node;
        bool flag=false;
        while(k){
            base=floor(log2(k));
            u=up[u][base];
            if(u==-1){
                flag=true;
                cout<<"-1"<<'\n';
                break;
            }
            k-=pow(2,base);
        }
        if(!flag){
            cout<<u<<'\n';
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