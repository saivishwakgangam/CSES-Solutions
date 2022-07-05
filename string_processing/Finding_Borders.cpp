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
    string s;
    cin>>s;
    ll n=s.length();
    vector<ll>z(n,0);
    ll l=0,r=0;
    for(ll i=1;i<n;i++){
        if(i<=r){
            z[i]=min(r-i+1,z[i-l]);
        }
        while(i+z[i]<n&&s[i+z[i]]==s[z[i]]){
            ++z[i];
        }
        if(i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }

    }
    vector<ll>borders;
    for(ll i=1;i<n;i++){
        if(i+z[i]==n){
            borders.push_back(z[i]);
        }
    }
    sort(borders.begin(),borders.end());
    for(auto ele:borders){
        cout<<ele<<" ";
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