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
bool compare(const pair<ll,ll>&p1,const pair<ll,ll>&p2){
    if(p1.second<p2.second){
        return true;
    }
    else if(p1.second==p2.second){
        return (p1.first<p2.first);
    }
    return false;
}
void solve()
{
    ll n,temp1,temp2;
    cin>>n;
    vector<pair<ll,ll>>input;
    fori(i,n){
        cin>>temp1>>temp2;
        input.push_back(make_pair(temp1,temp2));
    }
    sort(input.begin(),input.end(),compare);
    multimap<ll,ll>deadlines;
    fori(i,n){
        deadlines.insert({input[i].second,i});
    }
    multimap<ll,ll>rewards;
    fori(i,n){
        rewards.insert({(input[i].second-input[i].first),i});
    }
    ll max_reward=0;
    ll starting_time=0;
    ll min_deadline;
    while(!rewards.empty()){
        ll max_rew=(--rewards.end())->first;
        auto it=rewards.lower_bound(max_rew);
        max_rew=it->first;
        ll max_rew_index=it->second;
        auto it1=deadlines.begin();
        min_deadline=it1->second;
        ll deadline_difference=(input[max_rew_index].second-input[min_deadline].second);
        ll reward_difference=(max_rew-(input[min_deadline].second-input[min_deadline].first));
        if(deadline_difference>=reward_difference){
            // consider min_deadline
            max_reward+=(input[min_deadline].second-(input[min_deadline].first+starting_time));
            starting_time+=input[min_deadline].first;
            auto it2=rewards.lower_bound(input[min_deadline].second-input[min_deadline].first);
            rewards.erase(it2);
            deadlines.erase(it1);
        }
        else{
            //consider max_reward
            max_reward+=(input[max_rew_index].second-(input[max_rew_index].first+starting_time));
            starting_time+=(input[max_rew_index].first);
            rewards.erase(it);
            auto it2=deadlines.lower_bound(input[max_rew_index].second);
            deadlines.erase(it2);

        }
    }
    cout<<max_reward;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}