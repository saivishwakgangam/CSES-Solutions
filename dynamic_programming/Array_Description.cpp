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
void solve()
{
    ll n,m,temp;
    cin>>n>>m;
    vector<ll>ele;
    fori(i,n){
        cin>>temp;
        ele.push_back(temp);
    }
    ll ways[n][m+2];
    memset(ways,0,sizeof(ways));
    for(ll i=0;i<n;i++){
        if(i==0){
            if(ele[i]==0){
                for(ll j=1;j<=m;j++){
                    ways[i][j]=1;
                }
            }
            else{
                ways[i][ele[i]]=1;
            }
        }
        else{
            if(ele[i]==0){
                for(ll j=1;j<=m;j++){
                    ways[i][j]=(ways[i-1][j-1]+ways[i-1][j]+ways[i-1][j+1])%mod;
                }
            }
            else{
                ways[i][ele[i]]=(ways[i-1][ele[i]-1]+ways[i-1][ele[i]]+ways[i-1][ele[i]+1])%mod;
            }
        }
    }
    ll no_of_ways=0;
    for(ll j=1;j<=m;j++){
        no_of_ways=(no_of_ways+ways[n-1][j])%mod;
    }
    cout<<no_of_ways;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}