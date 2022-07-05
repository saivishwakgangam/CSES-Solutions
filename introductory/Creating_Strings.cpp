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
set<string>result;
set<string>::iterator it;
void permutations(string input,ll index){
  if(index==input.length()){
      result.insert(input);
      return;
  }
  for(ll i=index;i<input.length();i++){
      swap(input[index],input[i]);
      permutations(input,index+1);
      swap(input[index],input[i]);

  }
}
void solve()
{
    string input;
    cin>>input;
    permutations(input,0);
    cout<<result.size()<<'\n';
    for(it=result.begin();it!=result.end();it++){
        cout<<*it<<endl;
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