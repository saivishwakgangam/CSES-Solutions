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

void solve()
{
    ll n,temp;
    cin>>n;
    vector<ll>ele;
    fori(i,n){
        cin>>temp;
        ele.push_back(temp);
    }
    ll prefix_sum=0;
    ll res=0;
    ll rem;
    map<ll,ll>prefix_map;
    prefix_map[0]=1;
    fori(i,n){
        prefix_sum+=ele[i];
        rem=((prefix_sum%n)+n)%n;
        if(prefix_map.find(rem)!=prefix_map.end()){
            res+=(prefix_map[rem]);
        }
        prefix_map[rem]++;
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