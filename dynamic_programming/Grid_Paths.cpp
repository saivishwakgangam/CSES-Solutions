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
const ll mod=1e9+7;
void solve()
{
    ll n;
    string temp;
    cin>>n;
    vector<string>input;
    fori(i,n){
        cin>>temp;
        input.push_back(temp);
    }
    ll dp[n][n];
    for(ll i=n-1;i>=0;i--){
        for(ll j=n-1;j>=0;j--){
            if(i==n-1&&j==n-1){
                if(input[i][j]=='*'){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=1;
                }
            }
            else if(i==n-1){
                if(input[i][j]=='*'){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i][j+1];
                }
            }
            else if(j==n-1){
                if(input[i][j]=='*'){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=dp[i+1][j];
                }
            }
            else{
                if(input[i][j]=='*'){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=(dp[i+1][j]+dp[i][j+1])%mod;
                }
            }
        }
    }
    cout<<dp[0][0];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}