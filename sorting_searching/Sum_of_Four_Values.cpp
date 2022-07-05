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
    ll n,temp,sum;
    cin>>n>>sum;
    vector<ll>ele;
    fori(i,n){
        cin>>temp;
        ele.push_back(temp);
    }
    ll target;
    map<ll,pair<ll,ll>>sums_frequency;
    for(ll i=0;i<n-1;i++){
        for(ll j=i+1;j<n;j++){
            target=sum-(ele[i]+ele[j]);
            if(sums_frequency.find(target)!=sums_frequency.end()){
                auto it=sums_frequency.find(target);
                cout<<i+1<<" "<<j+1<<" "<<it->second.first+1<<" "<<it->second.second+1;
                return;

            }
        }
        for(ll k=0;k<i;k++){
            sums_frequency[ele[k]+ele[i]]=make_pair(k,i);
        }
    }
    cout<<"IMPOSSIBLE";
    return;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}