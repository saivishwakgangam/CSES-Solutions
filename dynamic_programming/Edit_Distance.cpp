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
    string input1,input2;
    cin>>input1;
    cin>>input2;
    ll len1=input1.length(),len2=input2.length();
    ll dp[len1+1][len2+1];
    for(ll i=0;i<=len1;i++){
        for(ll j=0;j<=len2;j++){
            if(i==0&&j==0){
                dp[i][j]=0;
            }
            else if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
            else{
                if(input1[i-1]==input2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(1+dp[i-1][j],min(1+dp[i][j-1],1+dp[i-1][j-1]));
                }
            }
        }
    }
    cout<<dp[len1][len2];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}