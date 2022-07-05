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
const ll inf=1e14+1;
void floyd_warshal(vector<vector<ll>>&distance,ll n){
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                distance[i][j]=min(distance[i][j],distance[i][k]+distance[k][j]);
            }
        }
    }
}
void solve()
{
    ll n,m,q;
    cin>>n>>m>>q;
    ll a,b,w;
    vector<vector<bool>>visited(n+1,vector<bool>(n+1,false));
    vector<vector<ll>>distance(n+1,vector<ll>(n+1,inf));
    for(ll i=1;i<=n;i++){
        distance[i][i]=0;
    }
    while(m--){
        cin>>a>>b>>w;
        distance[a][b]=min(distance[a][b],w);
        distance[b][a]=min(distance[b][a],w);
    }
    floyd_warshal(distance,n);
    while(q--){
        cin>>a>>b;
        if(distance[a][b]>=inf){
            cout<<"-1";
        }
        else{
            cout<<distance[a][b];
        }
        cout<<'\n';
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