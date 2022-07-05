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

bool isValid(vector<string>&ele,ll i,ll j,vector<vector<bool>>&visited){
    if(i<0||i>=ele.size()||j<0||j>=ele[0].size()){
        return false;
    }
    if(ele[i][j]=='#'){
        return false;
    }
    if(visited[i][j]){
        return false;
    }
    return true;

}
void dfs(ll i,ll j,vector<string>&ele,vector<vector<bool>>&visited){
    visited[i][j]=true;
    if(isValid(ele,i-1,j,visited)){
        dfs(i-1,j,ele,visited);
    }
    if(isValid(ele,i+1,j,visited)){
        dfs(i+1,j,ele,visited);
    }
    if(isValid(ele,i,j-1,visited)){
        dfs(i,j-1,ele,visited);
    }
    if(isValid(ele,i,j+1,visited)){
        dfs(i,j+1,ele,visited);
    }
}
void solve()
{
    ll n,m;
    string temp;
    cin>>n>>m;
    vector<string>ele;
    fori(i,n){
        cin>>temp;
        ele.push_back(temp);
    }
    ll res=0;
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(ele[i][j]!='#'&&!visited[i][j]){
                res++;
                dfs(i,j,ele,visited);
            }
        }
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