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
bool final_flag=false;
string final_path;
ll dx[4]={1,0,-1,0};
ll dy[4]={0,1,0,-1};
string movement="DRUL";
bool isValid(ll i,ll j,ll n,ll m,vector<string>&maze,vector<vector<bool>>&visited){
    if(i<0||i>=n||j<0||j>=m){
        return false;
    }
    if(visited[i][j]){
        return false;
    }
    if(maze[i][j]=='#'||maze[i][j]=='M'){
        return false;
    }
    //check four directions if there is a maze
    //left
    if(j-1>=0){
        if(maze[i][j-1]=='M'){
            return false;
        }
    }
    //right
    if(j+1<m){
        if(maze[i][j+1]=='M'){
            return false;
        }
    }
    //up
    if(i-1>=0){
        if(maze[i-1][j]=='M'){
            return false;
        }
    }
    //down
    if(i+1<n){
        if(maze[i+1][j]=='M'){
            return false;
        }
    }
    return true;
}
void bfs(ll s_r,ll s_c,ll n,ll m,vector<string>&maze,vector<vector<bool>>&visited,vector<vector<ll>>&distance){
    queue<tuple<ll,ll,string>>q;
    ll i,j;
    string path;
    tuple<ll,ll,string>temp;
    q.push({s_r,s_c,""});
    visited[s_r][s_c]=true;
    distance[s_r][s_c]=0;
    while(!q.empty()){
        temp=q.front();
        q.pop();
        tie(i,j,path)=temp;
        if(i==0||i==n-1||j==0||j==m-1){
            final_flag=true;
            final_path=path;
            return;
        }
        for(ll k=0;k<4;k++){
            if(isValid(i+dx[k],j+dy[k],n,m,maze,visited)){
                visited[i+dx[k]][j+dy[k]]=true;
                distance[i+dx[k]][j+dy[k]]=1+distance[i][j];
                string t=path;
                t.push_back(movement[k]);
                q.push({i+dx[k],j+dy[k],t});
            }
        }
    }
}
void solve()
{
    ll n,m;
    cin>>n>>m;
    string temp;
    vector<string>maze;
    for(ll i=0;i<n;i++){
        cin>>temp;
        maze.push_back(temp);
    }
    vector<vector<bool>>visited(n,vector<bool>(m,false));
    vector<vector<ll>>distance(n,vector<ll>(m,0));
    ll s_r,s_c;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(maze[i][j]=='A'){
                s_r=i;
                s_c=j;
            }
        }
    }
    bfs(s_r,s_c,n,m,maze,visited,distance);
    if(final_flag){
        cout<<"YES"<<'\n';
        cout<<final_path.length()<<'\n';
        cout<<final_path;
        return;
    }
    cout<<"NO";
    
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}