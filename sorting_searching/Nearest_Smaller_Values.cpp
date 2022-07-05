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
    ll n,temp;
    cin>>n;
    vector<ll>ele;
    fori(i,n){
        cin>>temp;
        ele.push_back(temp);
        
    }
    vector<ll>result(n,0);
    stack<ll>st;
    for(ll i=n-1;i>=0;i--){
       if(st.empty()){
           st.push(i);
       }
       else{
           if(ele[i]>=ele[st.top()]){
               st.push(i);
           }
           else{
               while(!st.empty()&&ele[i]<ele[st.top()]){
                   result[st.top()]=i+1;
                   st.pop();
               }
               st.push(i);
           }
       }
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