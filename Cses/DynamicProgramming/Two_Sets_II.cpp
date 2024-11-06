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

/* solution */
ll n, target;
ll dp[501][130000];

ll rec(ll i, ll t)
{
    if (t == 0) return (1 % mod);
    if (t < 0 || i > n) return (0);
    if (dp[i][t] != -1) return dp[i][t];
    dp[i][t] = (rec(i+1, t - i) + rec(i+1, t)) % mod;
    return (dp[i][t]);
}

void solve()
{
    cin >> n;
    ll tot = n * (n + 1) / 2;
    if (tot%2)
    {
        cout << "0\n";
        return ;
    }
    target = tot / 2;
    for (ll i = 0; i <= n; i++)
        for (ll j = 0; j <= target; j++) dp[i][j] = -1;
    //
    cout << (rec(1, target) * inverse(2)) % mod << '\n';
}
/* main funciton */
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return (0);
}
