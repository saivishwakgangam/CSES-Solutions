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
ll min_difference=LLONG_MAX;
void find_min(vector<ll>&ele,ll index,ll curr_sum,ll total_sum){
    if(index==ele.size()){
        min_difference=min(min_difference,abs(curr_sum-(total_sum-curr_sum)));
        return;
    }
    //include element or dont include element
    curr_sum+=ele[index];
    find_min(ele,index+1,curr_sum,total_sum);
    //dont include element
    curr_sum-=ele[index];
    find_min(ele,index+1,curr_sum,total_sum);

}
void solve()
{
    ll n,temp;
    cin>>n;
    vector<ll>ele;
    ll total_sum=0;
    fori(i,n){
        cin>>temp;
        total_sum+=temp;
        ele.push_back(temp);
    }
    find_min(ele,0,0,total_sum);
    cout<<min_difference;
    

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}