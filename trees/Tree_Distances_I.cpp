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
ll max(ll a,ll b){
    return ((a>b)?a:b);
}
void dfs(ll node,ll parent,vector<ll>adj_list[],vector<ll>&depth){
    ll d=0;
    for(auto child:adj_list[node]){
        if(child==parent)continue;
        dfs(child,node,adj_list,depth);
        d=max(d,1+depth[child]);
    }
    depth[node]=d;
}
void fill_partial_answer(ll node,ll parent,ll partial_ans,vector<ll>&ans,vector<ll>&depth,vector<ll>adj_list[]){
  vector<ll>prefix_max,suffix_max;
  for(auto child:adj_list[node]){
      if(child!=parent){
          prefix_max.push_back(depth[child]);
          suffix_max.push_back(depth[child]);
      }
  }
  for(int i=1;i<prefix_max.size();i++){
      prefix_max[i]=max(prefix_max[i],prefix_max[i-1]);
  }
  for(int i=suffix_max.size()-2;i>=0;i--){
      suffix_max[i]=max(suffix_max[i],suffix_max[i+1]);
  }
  ll child_no=0;
  for(auto child:adj_list[node]){
      if(child!=parent){
        ll op1=(child_no==0)?INT_MIN:prefix_max[child_no-1];
        ll op2=(child_no==suffix_max.size()-1)?INT_MIN:suffix_max[child_no+1];
        ll p_ans=1+max(partial_ans,max(op1,op2));
        fill_partial_answer(child,node,p_ans,ans,depth,adj_list);
        child_no++;
      }
  }
  ans[node]=1+max(partial_ans,((prefix_max.empty())?-1:prefix_max.back()));
  
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
    vector<ll>depth(n+1,0);
    dfs(1,-1,adj_list,depth);
    vector<ll>ans(n+1,0);
    fill_partial_answer(1,-1,-1,ans,depth,adj_list);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
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