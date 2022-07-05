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

void dfs(vector<ll>adj_list[],vector<ll>&result,ll curr_node,ll prev_node){
    for(auto adj_node:adj_list[curr_node]){
        if(adj_node==prev_node)continue;
        dfs(adj_list,result,adj_node,curr_node);
        result[curr_node]+=result[adj_node];
    }
}
void solve()
{
    ll n,temp;
    cin>>n;
    vector<ll>ele;
    fori(i,n-1){
        cin>>temp;
        ele.push_back(temp);
    }
    vector<ll>adj_list[n+1];
    for(ll i=0;i<n-1;i++){
        adj_list[ele[i]].push_back(i+2);
    }
    vector<ll>result(n+1,1);
    dfs(adj_list,result,1,0);
    for(ll i=1;i<=n;i++){
        cout<<result[i]-1<<" ";
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