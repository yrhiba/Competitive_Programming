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

vector<ll> pre;
vector<ll> nodes;

vector<bool> vis;

vector<ll> ans;

void rec(ll node = 0, ll dis = 0)
{
    pre[node] = dis;
    vis[node] = true;
    nodes[node] = 1;
    for (ll nx : g[node])
        if (!vis[nx])
        {
            rec(nx, dis + 1);
            nodes[node] += nodes[nx];
            pre[node] += pre[nx];
        }
}

void finalRec(ll node, ll parent = -1, ll dis = 0, ll numNodes = 0)
{
    ans[node] = pre[node] - (dis * nodes[node]);

    if (parent != -1)
    {
        ans[node] += ans[parent] - (pre[node] - ((dis - 1) * nodes[node]));
        ans[node] += numNodes; //
    }

    for (ll nx : g[node])
        if (nx != parent)
            finalRec(nx, node, dis + 1
                , numNodes + (nodes[node] - nodes[nx])
            );
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

    nodes = vector<ll>(n, 0);
    pre = vector<ll>(n, -1);

    vis = vector<bool>(n, false);
    rec(0, 0);

    ans = vector<ll>(n, 0);
    finalRec(0);

    for (ll i = 0; i < n; i++)
        cout << ans[i] << " \n"[i+1 == n];
}

/* main funciton */
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return (0);
}
