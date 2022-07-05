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
const long long mod=1e9+7;
void solve()
{
    ll k;
    map<string,bool>mp;
    string s,temp;
    cin>>s;
    cin>>k;
    while(k--){
        cin>>temp;
        mp[temp]=true;
    }
    ll n=s.length();
    vector<ll>dp(n,0);
    for(int i=n-1;i>=0;i--){
        string t="";
        for(int j=i;j<n;j++){
            t+=s[j];
            if(mp[t]){
                if(j==n-1){
                    dp[i]=(1+dp[i])%mod;
                }
                else{
                    dp[i]=(dp[i]+dp[j+1])%mod;
                }
            }
        }
    }
    cout<<dp[0];



}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}