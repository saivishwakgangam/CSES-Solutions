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
bool compare(const pair<pair<ll,char>,ll>&p1,const pair<pair<ll,char>,ll>&p2){
    return (p1.first.first)<(p2.first.first);

}
void solve()
{
    ll n,start,end;
    cin>>n;
    vector<pair<ll,ll>>times;
    fori(i,n){
        cin>>start>>end;
        times.push_back(make_pair(start,end));
    }
    vector<pair<pair<ll,char>,ll>>flatten_time;
    fori(i,n){
        flatten_time.push_back(make_pair(make_pair(times[i].first,'a'),i));
        
    }
    fori(i,n){
        flatten_time.push_back(make_pair(make_pair(times[i].second,'d'),i));
    }
    stable_sort(flatten_time.begin(),flatten_time.end(),compare);
    ll min_rooms=0;
    ll res=LLONG_MIN;
    map<ll,ll>rooms;
    fori(i,flatten_time.size()){
        if(flatten_time[i].first.second=='a'){
            min_rooms++;
        }
        else{
            min_rooms--;
        }
        res=max(res,min_rooms);
    }
    multimap<ll,ll>room_allocation;
    for(ll i=1;i<=res;i++){
        room_allocation.insert({-1,i});
    }
    fori(i,flatten_time.size()){
        if(flatten_time[i].first.second=='a'){
            auto it=room_allocation.lower_bound(-1);
            ll room_number=it->second;
            room_allocation.erase(it);
            room_allocation.insert({flatten_time[i].second,room_number});
            rooms[flatten_time[i].second]=room_number;

        }
        else{ 
            auto it=room_allocation.lower_bound(flatten_time[i].second);
            ll room_number=it->second;
            room_allocation.erase(it);
            room_allocation.insert({-1,room_number});


        }
    }
    cout<<res<<"\n";
    for(auto i:rooms){
        cout<<i.second<<" ";
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