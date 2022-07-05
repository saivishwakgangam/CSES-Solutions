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

void solve()
{
    ll n,k,temp,point1,point2,res;
    cin>>n>>k;
    set<ll>points;
    multiset<ll,greater<ll>>diff;
    diff.insert(n);
    points.insert(0);
    points.insert(n);
    for(i,k){
        cin>>temp;
        auto it=points.upper_bound(temp);
        point1=*it;
        auto it1=--it;
        point2=*it1;
        points.insert(temp);
        auto it3=diff.lower_bound(point1-point2);
        diff.erase(it3);
        diff.insert(point1-temp);
        diff.insert(temp-point2);
        res=*(diff.begin());
        cout<<res<<" ";
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