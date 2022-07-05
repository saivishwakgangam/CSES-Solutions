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
void dfs(ll node,ll parent,vector<ll>adj_list[],vector<ll>&euler_path,vector<ll>&first,vector<ll>&height,int h=0){
    height[node]=h;
    first[node]=euler_path.size();
    euler_path.push_back(node);
    for(auto child:adj_list[node]){
        if(child!=parent){
            dfs(child,node,adj_list,euler_path,first,height,h+1);
            euler_path.push_back(node);
        }
    }
}
ll construct_segment_tree(vector<ll>&segment_tree,vector<ll>&euler_path,vector<ll>&height,ll sp,ll l,ll r){
    if(l==r){
        return (segment_tree[sp]=euler_path[l]);
    }
    ll mid=(l+r)/2;
    ll temp1=construct_segment_tree(segment_tree,euler_path,height,2*sp+1,l,mid);
    ll temp2=construct_segment_tree(segment_tree,euler_path,height,2*sp+2,mid+1,r);
    if(height[temp1]<=height[temp2]){
        return (segment_tree[sp]=temp1);
    }
    return (segment_tree[sp]=temp2);
}
ll get_minimum(vector<ll>&segment_tree,vector<ll>&height,ll sp,ll a_l,ll a_r,ll t_l,ll t_r){
    if(t_l>a_r||t_r<a_l){
        return -1;
    }
    if(a_l>=t_l&&a_r<=t_r){
        return segment_tree[sp];
    }
    ll mid=(a_l+a_r)/2;
    ll temp1=get_minimum(segment_tree,height,2*sp+1,a_l,mid,t_l,t_r);
    ll temp2=get_minimum(segment_tree,height,2*sp+2,mid+1,a_r,t_l,t_r);
    if(temp1==-1){
        return temp2;
    }
    if(temp2==-1){
        return temp1;
    }
    if(height[temp1]<=height[temp2]){
        return temp1;
    }
    return temp2;
}
void solve()
{
    ll n,m,b;
    cin>>n;
    vector<ll>adj_list[n+1];
    for(ll i=0;i<n;i++){
        cin>>m;
        while(m--){
            cin>>b;
            adj_list[i].push_back(b);
            adj_list[b].push_back(i);
        }
    }
    //construct dfs of the tree
    vector<ll>euler_path;
    vector<ll>first(n,0);
    vector<ll>height(n,0);
    dfs(0,-1,adj_list,euler_path,first,height);
    //construct segment tree
    ll s=euler_path.size()-1;
    ll total_nodes=2*s-1;
    ll seg_size=pow(2,ceil(log2(total_nodes)));
    vector<ll>segment_tree(seg_size,0);
    ll min_node=construct_segment_tree(segment_tree,euler_path,height,0,0,s-1);
    ll q,a1,b1;
    cin>>q;
    while(q--){
        cin>>a1>>b1;
        if(a1==b1){
            cout<<a1<<endl;
            continue;
        }
        ll index1=first[a1];
        ll index2=first[b1];
        if(index1>index2){
            swap(index1,index2);
        }
        ll min_node=get_minimum(segment_tree,height,0,0,s-1,index1,index2);
        cout<<min_node<<endl;
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