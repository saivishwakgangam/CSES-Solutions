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
    if(a>b){
        return a;
    }
    return b;
}
ll max_reward(vector<pair<pair<ll,ll>,ll>>&input,ll i,ll n,ll starting_time){
    if(i==n){
        return 0;
    }
    if(input[i].first.first>starting_time){
        return max(input[i].second+max_reward(input,i+1,n,input[i].first.second),max_reward(input,i+1,n,starting_time));
    }
    return max_reward(input,i+1,n,starting_time);
}
void solve()
{
    ll n,st,et,reward;
    cin>>n;
    vector<pair<pair<ll,ll>,ll>>input;
    fori(i,n){
        cin>>st>>et>>reward;
        input.push_back(make_pair(make_pair(st,et),reward));
    }
    ll res=max_reward(input,0,n,0);
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