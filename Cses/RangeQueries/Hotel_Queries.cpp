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
ll a[int(2e5 + 1)];
ll seg[int(2e5 + 1) * 4];

void setup(ll left, ll right, ll cur)
{
    if (left == right)
    {
        seg[cur] = a[left & right];
        return ;
    }
    ll mid = left + (right - left) / 2;
    setup(left, mid, cur*2+1);
    setup(mid+1, right, cur*2+2);
    seg[cur] = max(seg[cur*2+1], seg[cur*2+2]);
}

pair<ll, ll> query(ll r, ll left, ll right, ll cur)
{
    if (left == right)
    {
        if (seg[cur] >= r) return (make_pair(left, seg[left]));
        return (make_pair(-1, -1));
    }
    ll mid = left + (right - left) / 2;
    if (seg[cur*2+1] >= r) return query(r, left, mid, cur*2+1);
    return query(r, mid+1, right, cur*2+2);
}

void update(ll idx, ll r, ll left, ll right, ll cur)
{
    if (left == right)
    {
        if (left == idx) seg[cur] -= r;
        return ;
    }
    if (idx < left || idx > right) return ;
    ll mid = left + (right - left) / 2;
    update(idx, r, left, mid, cur*2+1);
    update(idx, r, mid+1, right, cur*2+2);
    seg[cur] = max(seg[cur*2+1], seg[cur*2+2]);
}

void solve()
{
    ll n, m; cin >> n >> m;
    for (ll i = 0; i < n; i++) cin >> a[i];
    setup(0, n-1, 0);
    for (ll i = 0; i < m; i++)
    {
        ll r; cin >> r;
        if (seg[0] < r) cout << 0 << " \n"[i+1 == m];
        else
        {
            auto q = query(r, 0, n-1, 0);
            update(q.first, r, 0, n-1, 0);
            cout << q.first + 1 << " \n"[i+1 == m];
        }
    }
}
/* main funciton */
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    preSetup();
    solve();
    return (0);
}
