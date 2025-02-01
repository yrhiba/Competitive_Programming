/*
yrhiba.github.io (c). 2022-2024

CSES Problem Set
High Score

link to the problem:
https://cses.fi/problemset/task/1673/
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
void solve()
{
    ll n, m; cin >> n >> m;

    vector<vector<ll>> ed;
    vector<vector<ll>> g(n);

    for (ll i = 0; i < m; i++)
    {
        ll a, b, x; cin >> a >> b >> x;
        a -= 1, b -= 1;
        ed.push_back({a, b, -x});
        g[b].push_back(a);
    }

    vector<bool> visFromEnd(n, false);
    queue<ll> q;
    q.push(n-1);
    visFromEnd[n-1] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto nx : g[node])
            if (!visFromEnd[nx])
            {
                q.push(nx);
                visFromEnd[nx] = true; 
            }
    }

    g = vector<vector<ll>>(n);
    for (auto &v : ed)
        g[v[0]].push_back(v[1]);

    vector<bool> visFromStart(n, false);
    q.push(0);
    visFromStart[0] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto nx : g[node])
            if (!visFromStart[nx])
            {
                q.push(nx);
                visFromStart[nx] = true;
            }
    }

    vector<ll> dist(n, 1e18);
    dist[0] = 0;
    for (ll i = 0; i+1 < n; i++)
        for (auto &v : ed)
            dist[v[1]] = min(dist[v[1]], dist[v[0]] + v[2]);

    for (auto &v : ed)
        if (visFromStart[v[0]]
        && visFromEnd[v[1]]
         && dist[v[0]] + v[2] < dist[v[1]])
        {
            cout << "-1\n";
            return ;
        }
    //
    cout << dist[n-1] * -1 << '\n';
}
/* main funciton */
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    preSetup();
    solve();
    return (0);
}
