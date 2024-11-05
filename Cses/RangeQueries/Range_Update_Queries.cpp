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
vector<ll> a;

void setup(vector<ll> &seg, ll left, ll right, ll cur)
{  
    if (left == right)
    {
        seg[cur] = a[left & right];
        return ;
    }
    ll mid = left + (right - left) / 2;
    setup(seg, left, mid, cur * 2 + 1);
    setup(seg, mid + 1, right, cur * 2 + 2);
    seg[cur] = 0;
}

void update(vector<ll> &seg, ll ql, ll qr, ll u, ll left, ll right, ll cur)
{
    if (ql <= left && right <= qr)
    {
        seg[cur] += u;
        return ;
    }
    if (ql > right || left > qr) return ;
    ll mid = left + (right - left) / 2;
    update(seg, ql, qr, u, left, mid, cur * 2 + 1);
    update(seg, ql, qr, u, mid+1, right, cur * 2 + 2);
}

ll query(vector<ll> &seg, ll idx, ll left, ll right, ll cur)
{
    if (left == right)
    {
        if (left == idx) return seg[cur];
        return (0);
    }
    if (idx < left || idx > right) return (0);
    seg[cur*2+1] += seg[cur];
    seg[cur*2+2] += seg[cur];
    seg[cur] = 0;
    ll mid = left + (right - left) / 2;
    return query(seg, idx, left, mid, cur*2+1)
        + query(seg, idx, mid+1, right, cur*2+2);
}


void solve()
{
    ll q; cin >> n >> q;
    a = vector<ll>(n);
    for (auto &i : a) cin >> i;
    vector<ll> seg(4*n);
    setup(seg, 0, n-1, 0);
    while (q--)
    {
        ll t; cin >> t;
        if (t == 1)
        {
            ll a, b, u; cin >> a >> b >> u;
            a -= 1, b -= 1;
            update(seg, a, b, u, 0, n-1, 0);
        }
        else if (t == 2)
        {  
            ll k; cin >> k;
            k -= 1;
            cout << query(seg, k, 0, n-1, 0) << '\n';
        }
        else exit(1); // impossible to happen
    }
    return ;
}
/* main funciton */
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    preSetup();
    solve();
    return (0);
}
