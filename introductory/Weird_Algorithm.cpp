#include <bits/stdc++.h>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define for(i,n) for(int i=0;i<(n);++i)
#define fora(i,a,n) for(int i=a;i<=(n);++i)
#define forad(i,a,n) for(int i=a;i>=(n);--i)
#define pb(v,temp) v.push_back(temp)

using namespace std;
using ll = long long;

void solve(ll n)
{
    while(n!=1)
    {
        cout<<n<<" ";
        if(n%2)
        {
            n=3*n+1;
        }
        else
        {
            n=n/2;
        }
    }
    cout<<n;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    solve(n);
    
    return 0;
}