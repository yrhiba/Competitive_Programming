/*
yrhiba.github.io (c). 2022-2024
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <cassert>
#include <random>
#include <sstream>
using namespace std;
# define all(x) begin(x), end(x)
# define rall(x) rbegin(x), rend(x)
typedef long long ll;

/* solution */
pair<ll, ll> bfs(ll node, vector<vector<ll>> &g)
{
    pair<ll, ll> ans = {-1, -1};
    ll n = int(g.size());
    vector<bool> vis(n, false);
    queue<pair<ll, ll>> q;
    vis[node] = true;
    q.push({node, 0});
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();
        ll curNode = cur.first;
        ll curW = cur.second;
        ans = max(ans, {curW, curNode});
        for (ll nx : g[curNode])
            if (!vis[nx])
            {
                vis[nx] = true;
                q.push({nx, curW + 1});
            }
    }
    return (ans);
}

void solve()
{
    ll n; cin >> n;
    vector<vector<ll>> g(n);
    for (ll i = 0; i+1 < n; i++)
    {
        ll a, b; cin >> a >> b;
        a -= 1, b -= 1;
        g[a].push_back(b); 
        g[b].push_back(a);
    }
    cout << bfs(bfs(0, g).second, g).first << '\n';
}
/* main funciton */
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return (0);
}
