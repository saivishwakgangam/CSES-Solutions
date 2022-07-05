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

int solve(ll n,ll m,ll diff,vector<ll>&des_size,vector<ll>&apt_size)
{

    ll ans=0,temp;
    sort(des_size.begin(),des_size.end());
    sort(apt_size.begin(),apt_size.end());
    ll i=0,j=0;
    while(i<n&&j<m)
    {
        if(abs(des_size[i]-apt_size[j])<=diff)
        {
            ans++;
            i++;
            j++;
        }
        else if(des_size[i]<apt_size[j])
        {
          i++;
        }
        else
        {
            j++;
        }
    }
    return ans;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,diff,temp;
    cin>>n>>m>>diff;
    vector<ll>des_size;
    vector<ll>apt_size;
    des_size.reserve(n);
    apt_size.reserve(m);
    for(i,n)
    {
        cin>>temp;
        pb(des_size,temp);
    }
    for(i,n)
    {
        cin>>temp;
        pb(apt_size,temp);
    }
    ll res=solve(n,m,diff,des_size,apt_size);
    cout<<res;
    return 0;
}