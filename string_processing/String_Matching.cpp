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
    string str,pattern;
    cin>>str;
    cin.get();
    cin>>pattern;
    const long long a=31;
    const long long b=1e9+9;
    vector<ll>p(str.length());
    for(ll i=0;i<str.length();i++){
        if(i==0){
            p[0]=1;
        }
        else{
            p[i]=(p[i-1]*a)%b;
        }
    }
    vector<ll>hash(str.length()+1,0);
    for(ll i=0;i<str.length();i++){
        hash[i+1]=(hash[i]+(str[i]-'a'+1)*p[i])%b;
    }
    long long pattern_hash=0;
    for(ll i=0;i<pattern.length();i++){
        pattern_hash=(pattern_hash+(pattern[i]-'a'+1)*p[i])%b;
    }
    ll matchings=0;
    for(ll i=0;i+pattern.length()-1<str.length();i++){
        ll current_hash=(hash[i+pattern.length()]-hash[i]+b)%b;
        if(current_hash==pattern_hash*p[i]%b){
            matchings++;
        }
    }
    cout<<matchings;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}