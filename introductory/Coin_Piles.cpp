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
    ll a,b;
    cin>>a>>b;
    if(a==0||b==0){
        if(a==0&&b==0){
            cout<<"YES";
            return;
        }
        cout<<"NO";
        return;
    }
    ll temp1=a,temp2=b;
    ll max_val=max(a,b);
    ll min_val=min(temp1,temp2);
    if(max_val>(min_val*2)){
        cout<<"NO";
        return;
    }
    if((max_val+min_val)%3){
        cout<<"NO";
        return;
    }
    cout<<"YES";
   
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