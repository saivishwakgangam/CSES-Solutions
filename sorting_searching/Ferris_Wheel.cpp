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

ll solve(ll n,ll x,vector<ll>&weights)
{
   ll ans=0,temp;
   sort(weights.begin(),weights.end());
   ll i=0,j=weights.size()-1;
   while(i<=j)
   {
     ans++;
     temp=weights[i]+weights[j];
     if(temp<=x)
     {
         i++;
         j--;
     }
     else{
         j--;
     }

   }
   return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,x,temp;
    cin>>n>>x;
    vector<ll>weights;
    for(i,n){
        cin>>temp;
        pb(weights,temp);
    }
    ll res=solve(n,x,weights);
    cout<<res;

    return 0;
}