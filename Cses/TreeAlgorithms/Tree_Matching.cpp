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
const int mod = int(1e9 + 7);
const double PI = 3.14159265359;
const string directions[8] {"D","R","U","L","DR","DL","TL","TR"};
const int dr[8] {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[8] {0, 1, 0, -1, 1, -1, -1, 1};
/* input - output */
void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
/* math */
ll gcd(ll a, ll b)
{
    if (b == 0) return (a);
    return (gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
    return ((a*b)/gcd(a, b));
}
ll lg2(ll x)
{
    ll r = ((x > 0) ? 0 : 1);
    while (x) x /= 2, r += 1;
    return (r);
}
ll lg10(ll x)
{
    ll r = ((x > 0) ? 0 : 1);
    while (x) x /= 10, r += 1;
    return (r);
}
ll power(ll x, ll p)
{
    if (p == 0) return (1);
    ll res = pow(x, p/2);
    if (p%2) return ((res * res) * x);
    return (res * res);
}
ll powermod(ll x, ll p, ll m = mod)
{
    if (p == 0) return (1);
    ll res = powermod(x, p/2, m) % m;
    if (p%2)
        return ((((res * res) % m) * (x % m)) % m);
    return ((res * res) % m);
}
ll inverse(ll x, ll m = mod)
{
    return (powermod(x, m-2, m));
}
/* global varibles */
const int MAX_N = int(5e5);
/* precalculation/setup */
void preSetup()
{
}
/* solution */
ll n;
vector<ll> g[int(2e5)];
bool vis[int(2e5)];
pair<ll, ll> dp[int(2e5)];

pair<ll, ll> rec(ll cur)
{
    if (dp[cur].first != -1) return dp[cur];

    vis[cur] = true;
    dp[cur] = {0, 0};

    vector<ll> childrens;
    for (auto nx : g[cur])
        if (!vis[nx]) childrens.push_back(nx);

    // skip picking the current node
    {
        for (int nx : childrens)
        {
            auto r = rec(nx);
            dp[cur].second += r.first;
        }
    }
   
    // pick an edge from the current node
    {
        for (int nx : childrens)
        {
            auto r = rec(nx);
            dp[cur].first = max(dp[cur].first, (1 + r.second) + (dp[cur].second - r.first));
        }
    }

    dp[cur].first = max(dp[cur].first, dp[cur].second);
    return dp[cur];
}

void solve()
{
    cin >> n;
    for (ll i = 0; i+1 < n; i++)
    {
        ll a, b; cin >> a >> b;
        a -= 1, b -= 1;
        g[a].push_back(b);
        g[b].push_back(a);
        dp[a] = dp[b] = make_pair(-1, -1);
        vis[a] = vis[b] = false;
    }    
    auto res = rec(0);
    cout << max(res.first, res.second) << '\n';
}
/* main funciton */
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    preSetup();
    solve();
    return (0);
}
