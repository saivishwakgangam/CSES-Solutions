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
vector<pair<ll,ll>>movements;
void toh(ll n,ll left,ll middle,ll right){
    if(n==0){
        return;
    }
    toh(n-1,left,right,middle);
    movements.push_back(make_pair(left,right));
    toh(n-1,middle,left,right);
}
void solve()
{
    ll n;
    cin>>n;
    toh(n,1,2,3);
    cout<<movements.size()<<"\n";
    for(auto i:movements){
        cout<<i.first<<" "<<i.second<<'\n';
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