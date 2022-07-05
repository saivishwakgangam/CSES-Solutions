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
const ll size=1e6+1;
vector<bool>primes(size,true);
vector<ll>primes_count(size,0);
void prime_sieve(){
    primes[1]=false;
    for(ll i=2;i*i<=size;i++){
        if(primes[i]){
            for(ll p=i*i;p<=size;p+=i){
                primes[p]=false;
            }
        }
    }
    ll count=0;
    for(ll i=2;i<=size;i++){
        if(primes[i]){
            count++;
        }
        primes_count[i]=count;
    }
}
void solve()
{
    ll n;
    cin>>n;
    cout<<primes_count[n];
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