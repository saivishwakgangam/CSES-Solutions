#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define fori(i,n) for(ll i=0;i<(n);++i)
#define fora(i,a,n) for(ll i=a;i<=(n);++i)
#define forad(i,a,n) for(ll i=a;i>=(n);--i)
#define pb(v,temp) v.push_back(temp)

using namespace std;
using ll = long long;
bool compare(pair<ll,ll>&p1,pair<ll,ll>&p2)
{
    return p1.first<=p2.first;
}
ll solve(ll customers,vector<pair<ll,ll>>&time)
{
    vector<pair<ll,bool>>v;
    for(auto i:time){
        pb(v,make_pair(i.first,true));
        pb(v,make_pair(i.second,false));
    }
    sort(v.begin(),v.end());
    ll res=0;
    ll ans=0;
    for(auto i:v){
        if(i.second){
            ans++;
            res=max(res,ans);
        }
        else{
            ans--;
            res=max(res,ans);
        }
      
    }
    return res;


}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll customers,temp1,temp2;
    cin>>customers;
    vector<pair<ll,ll>>time;
    fori(i,customers){
        cin>>temp1>>temp2;
        pb(time,make_pair(temp1,temp2));
    }
    ll res=solve(customers,time);
    cout<<res;
    return 0;
}