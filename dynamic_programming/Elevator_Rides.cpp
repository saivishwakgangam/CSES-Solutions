#include <bits/stdc++.h>

#define db1(x) cout << #x << "=" << x << '\n'
#define db2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << '\n'
#define db3(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << '\n'
#define fori(i, n) for (ll i = 0; i < (n); ++i)
#define fora(i, a, n) for (ll i = a; i <= (n); ++i)
#define forad(i, a, n) for (ll i = a; i >= (n); --i)
#define pb(v, temp) \
    ll temp;        \
    cin >> temp;    \
    v.push_back(temp)

using namespace std;
using ll = long long;
const ll inf = 1e9 + 7;
ll allVisited(vector<bool> &visited)
{
    ll index = -1;
    for (ll i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            index = i;
        }
    }
    return index;
}
ll min_rides(vector<ll> &ele, vector<bool> &visited, ll index, ll curr_weight, ll max_weight, ll rides)
{
    if (curr_weight > max_weight)
    {
        rides++;
    }
    if (index == ele.size())
    {
        ll temp = allVisited(visited);
        if (temp == -1)
        {
            return rides;
        }
        return inf;
    }
    //include the person
    visited[index] = true;
    ll min_ride1 = min_rides(ele, visited, index + 1, curr_weight + ele[index], max_weight, rides);
    //dont include the person
    visited[index]
}
void solve()
{
    ll n, max_weight, temp;
    cin >> n >> max_weight;
    vector<ll> ele;
    fori(i, n)
    {
        cin >> temp;
        ele.push_back(temp);
    }
    vector<bool> visited(n, false);
    ll res = min_rides(ele, visited, 0, 0, max_weight, 1);
    cout << res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}