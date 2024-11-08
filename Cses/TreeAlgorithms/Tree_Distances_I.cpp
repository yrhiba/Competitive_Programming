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
ll n;
vector<vector<ll>> g;

pair<ll, ll> bfs(ll node)
{
    pair<ll, ll> ans = {-1, -1};
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
    return ans;
}
 
void solve()
{
    cin >> n;
    g = vector<vector<ll>>(n);
    for (ll i = 0; i+1 < n; i++)
    {
        ll a, b; cin >> a >> b;
        a -= 1, b -= 1;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> diamter;
    diamter.push_back(bfs(0).second);
    diamter.push_back(bfs(diamter[0]).second);
    vector<ll> dis(n, 0);
    for (ll node : diamter)
    {
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
            dis[curNode] = max(dis[curNode], curW);
            for (ll nx : g[curNode])
                if (!vis[nx])
                {
                    vis[nx] = true;
                    q.push({nx, curW + 1});
                }
        }
    }
    for (ll i = 0; i < n; i++)
        cout << dis[i] << " \n"[i+1 == n];
}

/* main funciton */
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return (0);
}
