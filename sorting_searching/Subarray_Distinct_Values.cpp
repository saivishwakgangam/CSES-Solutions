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
    ll n,k,temp;
    cin>>n>>k;
    vector<ll>ele;
    fori(i,n){
        cin>>temp;
        ele.push_back(temp);
    }
    map<ll,ll>frequency;
    deque<ll>window;
    ll res=0;
    fori(i,n){
        window.push_back(i);
        frequency[ele[i]]++;
        if(frequency.size()>k){
            while(!window.empty()&&frequency.size()>k){
                frequency[ele[window.front()]]--;
                if(frequency[ele[window.front()]]==0){
                    frequency.erase(ele[window.front()]);
                }
                window.pop_front();

            }
            res+=(window.back()-window.front())+1;
        }
        else{
            res+=(window.back()-window.front())+1;
        }

    }
    cout<<res;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}