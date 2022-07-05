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

void solve(ll n,ll m,multiset<ll,greater<ll>>&tickets,vector<ll>&customers)
{
    vector<ll>ans;
    multiset<ll,greater<ll>>::iterator it;
    for(i,m){
        it=tickets.lower_bound(customers[i]);
        if(it==tickets.end())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(*it);
            tickets.erase(it);
        }

    }
    for(i,m)
    {
        cout<<ans[i]<<endl;
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,temp;
    cin>>n>>m;
    multiset<ll,greater<ll>>tickets;
    for(i,n){
        cin>>temp;
        tickets.insert(temp);
    }
    vector<ll>customers;
    for(i,m){
        cin>>temp;
        pb(customers,temp);
    }
    solve(n,m,tickets,customers);
    return 0;
}