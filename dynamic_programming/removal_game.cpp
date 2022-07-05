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


ll max_score(vector<ll>&ele,ll i,ll j,char turn){
    if(i>j){
        return 0;
    }
    if(turn=='a'){
        return max(ele[i]+max_score(ele,i+1,j,'b'),ele[j]+max_score(ele,i,j-1,'b'));
    }
    else if(turn=='b'){
        return max(max_score(ele,i+1,j,'a'),max_score(ele,i,j-1,'a'));
    }
    return 0;
}
void solve()
{
    ll n,temp;
    cin>>n;
    vector<ll>ele;
    fori(i,n){
        cin>>temp;
        ele.push_back(temp);
    }
    ll res=max_score(ele,0,n-1,'a');
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