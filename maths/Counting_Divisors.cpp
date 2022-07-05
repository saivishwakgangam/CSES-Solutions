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
long long s=1e6;
vector<ll>spf(s+1,0);
void prime_sieve(){
   spf[1]=1;
   for(ll i=2;i<=s;i++){
       spf[i]=i;
   }
   for(ll i=4;i<=s;i+=2){
       spf[i]=2;
   }
   for(ll p=3;p*p<=s;p++)
   {
       if(spf[p]==p){
           for(ll i=p*p;i<=s;i+=p){
               if(spf[i]==i){
                   spf[i]=p;
               }
           }
       }
   }
}
void solve()
{
   ll num;
   cin>>num;
   ll divisors=1;
   map<ll,ll>pf;
   while(num!=1){
       pf[spf[num]]++;
       num/=spf[num];
   }
   for(auto i:pf){
       divisors*=(i.second+1);
   }
   cout<<divisors;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    prime_sieve();
    ll t;
    cin>>t;
    while(t--){
    
        solve();
        cout<<'\n';
    }
    return 0;
}