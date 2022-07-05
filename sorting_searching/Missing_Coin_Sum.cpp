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

void solve()
{
    ll n,temp,sum=0;
    cin>>n;
    vector<ll>ele;
    fori(i,n){
        cin>>temp;
        sum+=temp;
        pb(ele,temp);
    }
    sort(ele.begin(),ele.end());
    ll res=1;
    for(ll i=0;i<n&&ele[i]<=res;i++)
    {
        res+=ele[i];
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