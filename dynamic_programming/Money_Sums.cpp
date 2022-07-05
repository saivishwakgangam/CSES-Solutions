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

bool subset_sum(vector<ll>&ele,ll target){
    ll len=ele.size();
    bool isPossible[len+1][target+1];
    for(ll i=0;i<=len;i++){
        for(ll j=0;j<=target;j++){
            if(j==0){
                isPossible[i][j]=true;
            }
            else if(i==0){
                isPossible[i][j]=false;
            }
            else{
                if(j>=ele[i-1]){
                    isPossible[i][j]=isPossible[i-1][j]||isPossible[i-1][j-ele[i-1]];
                }
                else{
                    isPossible[i][j]=isPossible[i-1][j];
                }
            }
        }
    }
    return isPossible[len][target];
}
void solve()
{
    ll n,temp,sum=0;
    cin>>n;
    vector<ll>ele;
    fori(i,n){
        cin>>temp;
        sum+=temp;
        ele.push_back(temp);
    }
    sort(ele.begin(),ele.end());
    ll mini=*min_element(ele.begin(),ele.end());
    set<ll>result;
    result.insert(sum);
    result.insert(mini);
    for(ll psum=mini+1;psum<sum;psum++){
        if(subset_sum(ele,psum)){
            result.insert(psum);
        }
    }
    cout<<result.size()<<'\n';
    for(const ll &num:result){
        cout<<num<<" ";
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