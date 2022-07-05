#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define db1(x) cout<<#x<<"="<<x<<'\n'
#define db2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<'\n'
#define db3(x,y,z) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<","<<#z<<"="<<z<<'\n'
#define fori(i,n) for(ll i=0;i<(n);++i)
#define fora(i,a,n) for(ll i=a;i<=(n);++i)
#define forad(i,a,n) for(ll i=a;i>=(n);--i)
#define pb(v,temp) ll temp;cin>>temp;v.push_back(temp)
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using ll = long long;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
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
    vector<ll>result;
    ordered_set os;
    fori(i,k){
       frequency[ele[i]]++; 
       os.insert(ele[i]);
    }

    ll index=(os.size()-1)/2;
    temp=*os.find_by_order(index);
    result.push_back(temp);
    for(ll i=k;i<n;i++){
        frequency[ele[i-k]]--;
        if(frequency[ele[i-k]]==0){
            os.erase(ele[i-k]);
        }
        frequency[ele[i]]++;
        os.insert(ele[i]);
        index=(os.size()-1)/2;
        temp=*os.find_by_order(index);
        result.push_back(temp);
        
    }
    for(auto i:result){
        cout<<i<<" ";
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