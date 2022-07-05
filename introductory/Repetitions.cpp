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
    string s;
    cin>>s;
    ll max_repetitions = 1;
    ll len = s.length();
    ll ptr1=0;
    ll ptr2;
    while(ptr1<len){
        ptr2=ptr1+1;
        while(ptr2<len&&s[ptr2]==s[ptr1]){
            ptr2++;
        }
        // cout<<(ptr2-ptr1)<<'\n';
        max_repetitions=max(max_repetitions,ptr2-ptr1);
        ptr1=ptr2;
    }
    max_repetitions = max(max_repetitions,ptr2-ptr1);
    cout<<max_repetitions;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}