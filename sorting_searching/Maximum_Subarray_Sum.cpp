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
bool check_negative(vector<ll>&ele){
    for(i,ele.size()){
        if(ele[i]>=0){
            return false;
        }
    }
    return true;
}
void solve()
{
   ll n,temp;
   cin>>n;
   ll maxi=LLONG_MIN;
   vector<ll>ele;
   ele.reserve(n);
   for(i,n){
       cin>>temp;
       maxi=max(temp,maxi);
       pb(ele,temp);
   }
   if(check_negative(ele)){
       cout<<maxi;
   }
   else
   {
        ll global=0,local=0;
        for(i,n){
            local=local+ele[i];
            global=max(global,local);
            if(local<0){
                local=0;
            }
        }
        cout<<global;
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