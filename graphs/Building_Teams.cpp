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

bool dfs(ll node,vector<ll>adj_list[],vector<ll>&team,ll colour){
    team[node]=colour;
    for(auto adj_nodes:adj_list[node]){
        ll new_colour;
        if(team[adj_nodes]==-1){
            if(colour==1){
                new_colour=2;
            }
            else{
                new_colour=1;
            }
            if(dfs(adj_nodes,adj_list,team,new_colour)==false){
                return false;
            }
        }
        else{
            if(team[adj_nodes]==team[node]){
                return false;
            }
        }
    }
    return true;
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
    vector<ll>team(n+1,-1);
    for(ll i=1;i<=n;i++){
        if(team[i]==-1){
            if(dfs(i,adj_list,team,1)==false){
                cout<<"IMPOSSIBLE";
                return;
            }
        }
    }
    for(ll i=1;i<=n;i++){
        cout<<team[i]<<" ";
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