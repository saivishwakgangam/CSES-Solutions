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
    ll row,column;
    cin>>row>>column;
    ll max_val=max(row,column);
    ll max_element=max_val*max_val;
    if(max_val%2){
        ll max_row=1;
        ll max_column=max_val;
        ll diff=abs(max_row-row)+abs(max_column-column);
        ll res=max_element-diff;
        cout<<res;
    }
    else{
        ll max_row=max_val;
        ll max_column=1;
        ll diff=abs(max_row-row)+abs(max_column-column);
        ll res=max_element-diff;
        cout<<res;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
    
        solve();
        cout<<'\n';
    }
    return 0;
}