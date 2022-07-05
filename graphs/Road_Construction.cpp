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
ll find(ll node,vector<ll>&parent){
    if(parent[node]==-1){
        return node;
    }
    return (parent[node]=find(parent[node],parent));
}
void solve()
{
    ll n,m,a,b,abs_root1,abs_root2;
    cin>>n>>m;
    vector<ll>parent(n+1,-1);
    vector<ll>rank(n+1,0);
    ll num_components=n;
    ll max_size=1;
    vector<ll>size(n+1,1);
    while(m--){
        cin>>a>>b;
        abs_root1=find(a,parent);
        abs_root2=find(b,parent);
        if(abs_root1==abs_root2){
            cout<<num_components<<" "<<max_size<<'\n';
        }
        else{
            //update values
            num_components--;
            if(rank[abs_root1]==rank[abs_root2]){
                rank[abs_root2]++;
                parent[abs_root1]=abs_root2;
                size[abs_root2]+=size[abs_root1];
                max_size=max(max_size,size[abs_root2]);
            }
            else if(rank[abs_root1]>rank[abs_root2]){
                parent[abs_root2]=abs_root1;
                size[abs_root1]+=size[abs_root2];
                max_size=max(max_size,size[abs_root1]);

            }
            else{
                parent[abs_root1]=abs_root2;
                size[abs_root2]+=size[abs_root1];
                max_size=max(max_size,size[abs_root2]);

            }
            cout<<num_components<<" "<<max_size<<'\n';
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