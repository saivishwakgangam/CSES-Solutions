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
    return (p1.second<p2.second);
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
    sort(input.begin(),input.end());
    multimap<ll,ll>rewards;
    fori(i,n){
        rewards.insert({(input[i].second-input[i].first),i});
    }
    ll max_reward=0;
    ll starting_time=0;
    map<ll,bool>allocation;
    ll min_deadline;
    fori(i,n){
        cout<<"hi";
        if(!allocation[i]){
            if(min_deadline=-1){
                min_deadline=i;
            }
            ll max_rew=(--rewards.end())->first;
            auto it=rewards.lower_bound(max_rew);
            max_rew=it->first;
            ll max_rew_index=it->second;
            ll deadline_difference=(input[max_rew_index].second-input[min_deadline].second);
            ll reward_difference=(max_rew-(input[min_deadline].second-input[min_deadline].first));
            if(deadline_difference<=reward_difference){
                // consider min_deadline
                max_reward+=(input[min_deadline].second-(input[min_deadline].first+starting_time));
                starting_time+=input[min_deadline].first;
                min_deadline=-1;
                auto it1=rewards.lower_bound(input[min_deadline].second-input[min_deadline].first);
                rewards.erase(it1);
                allocation[min_deadline]=true;
            }
            else{
                //consider max_reward
                max_reward+=(input[max_rew_index].second-input[max_rew_index].first+starting_time);
                starting_time+=(input[max_rew_index].first);
                rewards.erase(it);
                allocation[max_rew_index]=true;

            }
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