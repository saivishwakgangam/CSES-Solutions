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

void dfs(ll node,ll parent,vector<ll>&euler_path,vector<ll>&height,vector<ll>&first,vector<ll>adj_list[],int h=0){
    first[node]=euler_path.size();
    euler_path.push_back(node);
    height[node]=h;
    
    for(auto child:adj_list[node]){
        if(child!=parent){
            dfs(child,node,euler_path,height,first,adj_list,h+1);
            euler_path.push_back(node);
        }
    }
}
ll construct_segment_tree(vector<ll>&segment_tree,vector<ll>&euler_path,vector<ll>&height,ll sp,ll l,ll r){
    if(l==r){
        segment_tree[sp]=euler_path[l];
        return segment_tree[sp];
    }
    ll mid=(l+r)/2;
    ll temp1=construct_segment_tree(segment_tree,euler_path,height,2*sp+1,l,mid);
    ll temp2=construct_segment_tree(segment_tree,euler_path,height,2*sp+2,mid+1,r);
    if(height[temp1]<=height[temp2]){
        segment_tree[sp]=temp1;
    }
    else{
        segment_tree[sp]=temp2;
    }
    return segment_tree[sp];
}
ll get_minimum(vector<ll>segment_tree,vector<ll>&height,ll sp,ll a_l,ll a_r,ll t_l,ll t_r){
    //no overlap
    if(t_l>a_r||t_r<a_l){
       return -1;
    }
    //complete overlap
    if(a_l>=t_l&&a_r<=t_r){
        return segment_tree[sp];
    }
    // partial overlap
    ll mid=(a_l+a_r)/2;
    ll left=get_minimum(segment_tree,height,2*sp+1,a_l,mid,t_l,t_r);
    ll right=get_minimum(segment_tree,height,2*sp+2,mid+1,a_r,t_l,t_r);
    if(left==-1){
        return right;
    }
    if(right==-1){
        return left;
    }
    if(height[left]<=height[right]){
        return left;
    }
    return right;
    
    

}
void solve()
{
    ll n,m,q,a,b;
    cin>>n>>q;
    m=n-1;
    vector<ll>adj_list[n+1];
    for(int i=2;i<=n;i++){
        a=i;
        cin>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    //preparing the arrays
    vector<ll>euler_path;
    vector<ll>height(n+1,0);
    vector<ll>first(n+1,0);
    dfs(1,-1,euler_path,height,first,adj_list);
    //construct rmq segment tree this segment tree stores the nodes rather than minimum values
    ll s=euler_path.size();
    ll total_nodes=2*s-1;
    ll seg_size=pow(2,ceil(log2(total_nodes)));
    vector<ll>segment_tree(seg_size,0);
    ll min_node=construct_segment_tree(segment_tree,euler_path,height,0,0,s-1);
    while(q--){
        cin>>a>>b;
        ll index1=first[a];
        ll index2=first[b];
        if(index1>index2){
            swap(index1,index2);
        }
        ll min_height_node=get_minimum(segment_tree,height,0,0,s-1,index1,index2);
        cout<<min_height_node<<endl;
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