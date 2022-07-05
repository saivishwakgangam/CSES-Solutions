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
    ll n;
    cin>>n;
    ll sum=((n)*(n+1))/2;
    if(sum%2){
        cout<<"NO";
        return;
    }
    bool flag=false;
    ll target=sum/2;
    ll prefix_sum=0;
    map<ll,ll>prev_sum;
    prev_sum[0]=0;
    vector<ll>set1;
    vector<ll>set2;
    for(ll i=1;i<=n;i++){
        prefix_sum+=i;
        if(prev_sum.find(prefix_sum-target)!=prev_sum.end()){
            flag=true;
            auto it=prev_sum.find(prefix_sum-target);
            ll index=it->second+1;
            for(ll j=index;j<=i;j++){
                set1.push_back(j);
            }
            for(ll j=1;j<index;j++){
                set2.push_back(j);
            }
            for(ll j=i+1;j<=n;j++){
                set2.push_back(j);
            }
            break;

        }
        prev_sum[prefix_sum]=i;
    }
    if(flag){
        cout<<"YES"<<'\n';
        cout<<set1.size()<<'\n';
        for(auto i:set1){
            cout<<i<<" ";
        }
        cout<<'\n';
        cout<<set2.size()<<'\n';
        for(auto i:set2){
            cout<<i<<" ";
        }
    }
    else{
        cout<<"NO";
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