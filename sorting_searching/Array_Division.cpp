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
bool isPossible(vector<ll>&ele,ll k,ll sum){
    ll temp_sum=0;
    ll ans=0;
    for(ll i=0;i<ele.size();i++){
            if(ele[i]>sum){
                return false;
            }
            if(temp_sum+ele[i]>sum){
                temp_sum=0;
                ++ans;
            }
            temp_sum+=ele[i];
    }
    if(temp_sum>0){
        ans++;
    }
    return ans<=k;
}
void solve()
{
    ll n,k,temp,sum=0;
    cin>>n>>k;
    vector<ll>ele;
    fori(i,n){
        cin>>temp;
        sum+=temp;
        ele.push_back(temp);
    }
    ll first=0;
    ll last=sum;
    ll ans;
    while(first<=last){
        ll mid=(first+last)/2;
        if(isPossible(ele,k,mid)){
            ans=mid;
            last=mid-1;
        }
        else{
            first=mid+1;
        }
    }
    cout<<ans;

    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}