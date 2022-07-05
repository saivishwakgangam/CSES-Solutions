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
    ll n,temp;
    cin>>n;
    multiset<int>s;
    fori(i,n){
        cin>>temp;
        auto it=s.upper_bound(temp);
        if(it==s.end()){
            s.insert(temp);
        }
        else{
            s.erase(it);
            s.insert(temp);
        }
    }
    cout<<s.size();

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve(); 
    return 0;
}