#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define for(i,n) for(ll i=0;i<(n);++i)
#define fora(i,a,n) for(ll i=a;i<=(n);++i)
#define forad(i,a,n) for(ll i=a;i>=(n);--i)
#define pb(v,temp) v.push_back(temp)

using namespace std;
using ll = long long;
ll max(ll a,ll b){
    if(a>b){
        return a;
    }
    return b;
}
void solve()
{
    ll n,temp;
    cin>>n;
    vector<ll>ele;
    for(i,n){
        cin>>temp;
        pb(ele,temp);
    }
    map<ll,bool>mp;
    deque<ll>window;
    ll res=INT_MIN;
    for(i,n){
        if(window.empty()){
            window.push_back(i);
            mp[ele[i]]=true;
        }
        else{
            if(mp[ele[i]]){
                res=max(res,window.size());
                while(!window.empty()&&ele[window.front()]!=ele[i]){
                    mp[ele[window.front()]]=false;
                    window.pop_front();
                }
                mp[ele[window.front()]]=false;
                window.pop_front();
            }
            window.push_back(i);
            mp[ele[i]]=true;
        }
    }
    res=max(res,window.size());
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