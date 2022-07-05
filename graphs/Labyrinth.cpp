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
string final_path;
ll final_distance;
bool final_flag=false;
string movement="URDL";
ll dx[4]={-1,0,1,0};
ll dy[4]={0,1,0,-1};
bool isValid(ll x,ll y,ll n,ll m,vector<string>&ele,vector<vector<bool>>&visited){
    if(x<0||x>=n||y<0||y>=m){
        return false;
    }
    if(visited[x][y]&&ele[x][y]=='#'){
        return false;
    }
    return true;
}
void bfs(ll s_r,ll s_c,ll n,ll m,vector<string>&ele,vector<vector<ll>>&distance,vector<vector<bool>>&visited,string path){
    queue<tuple<ll,ll,string>>q;
    q.push(make_tuple(s_r,s_c,path));
    distance[s_r][s_c]=0;
    while(!q.empty()){
        tuple<ll,ll,string>temp=q.front();
        q.pop();
        ll a,b;
        string p;
        tie(a,b,p)=temp;
        if(!visited[a][b]){
            visited[a][b]=true;
            for(ll i=0;i<4;i++){
             if(isValid(a+dx[i],b+dy[i],n,m,ele,visited)){
                if(ele[a+dx[i]][b+dy[i]]=='B'){
                    final_flag=true;
                    final_distance=1+distance[a][b];
                    final_path=p;
                    final_path+=movement[i];
                    return;
                }
                string temp=p;
                temp+=movement[i];
                distance[a+dx[i]][b+dy[i]]=1+distance[a][b];
                q.push(make_tuple(a+dx[i],b+dy[i],temp));
            }
        }
        
        }
    }
}
void solve()
{
    ll n,m;
    string temp;
    cin>>n>>m;
    vector<string>ele;
    fori(i,n){
        cin>>temp;
        ele.push_back(temp);
    }
    ll s_r,s_c,e_r,e_c;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(ele[i][j]=='A'){
                s_r=i;
                s_c=j;
            }
            else if(ele[i][j]=='B'){
                e_r=i;
                e_c=j;
            }
        }
    }
    vector<vector<ll>>distance(n,vector<ll>(m,0));
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    bfs(s_r,s_c,n,m,ele,distance,visited,"");
    if(final_flag){
        cout<<"YES"<<'\n'<<final_distance<<'\n'<<final_path;
    }
    else{
        cout<<"NO";
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