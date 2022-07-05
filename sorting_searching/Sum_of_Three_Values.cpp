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
    ll n,sum,temp;
    cin>>n>>sum;
    vector<pair<ll,ll>>ele;
    fori(i,n){
        cin>>temp;
        ele.push_back(make_pair(temp,i));
    }
    sort(ele.begin(),ele.end());
    bool flag;
    ll target,index1,index2;
    fori(i,n){
        flag=false;
        temp=ele[i].first;
        vector<pair<ll,ll>>temp1=ele;
        temp1.erase(temp1.begin()+i);
        ll j=0;
        ll k=temp1.size()-1;
        target=sum-ele[i].first;
        while(j<k){
            if(temp1[j].first+temp1[k].first==target){
                flag=true;
                index1=temp1[j].second;
                index2=temp1[k].second;
                break;
            }
            else if(temp1[j].first+temp1[k].first>target){
                k--;
            }
            else {
                j++;
            }
        }
        if(flag){
            cout<<ele[i].second+1<<" "<<index1+1<<" "<<index2+1;
            break;
        }

        
    }
    if(!flag){
        cout<<"IMPOSSIBLE";
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