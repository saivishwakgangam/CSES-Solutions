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

bool compare(const pair<pair<ll,ll>,ll>&p1,const pair<pair<ll,ll>,ll>&p2){
    return (p1.first.first<p2.first.first);
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
    sort(input.begin(),input.end(),compare);
    vector<ll>arrival_time;
    fori(i,n){
        arrival_time.push_back(input[i].first.first);
    }
    vector<ll>dp(n+1,0);
    ll ending_time,index;
    for(ll i=n-1;i>=0;i--){
        ending_time=input[i].first.second;
        index=upper_bound(arrival_time.begin(),arrival_time.end(),ending_time)-arrival_time.begin();
        dp[i]=max(input[i].second+dp[index],dp[i+1]);

    }
    cout<<dp[0];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}