#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define fori(i,n) for(ll i=0;i<(n);++i)
#define fora(i,a,n) for(ll i=a;i<=(n);++i)
#define forad(i,a,n) for(ll i=a;i>=(n);--i)
#define pb(v,temp) v.push_back(temp)
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
template<class T> using oset =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
void solve()
{
    ll n,temp;
    cin>>n;
    if(n==1){
        cout<<"1";
    }
    else{
        oset<ll>s;
        fori(i,n){
            s.insert(i+1);
        }
        ll index=1%n;
        while(!s.empty()){
            temp=*s.find_by_order(index);
            s.erase(temp);
            if(!s.empty()){
                index=(1+index)%s.size();
            }
            cout<<temp<<" ";
            

        }
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