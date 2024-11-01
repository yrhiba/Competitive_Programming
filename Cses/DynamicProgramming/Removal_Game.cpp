/*
yrhiba.github.io (c). 2022-2024

CSES Problem Set
Removal Game

link to the problem:
https://cses.fi/problemset/task/1097/
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
vector<ll> a;
pair<ll, ll> dp[5000][5000][2];

pair<ll, ll> rec(ll i, ll j, ll k)
{
    if (i > j) return {0, 0};
    if (i == j)
    {
        if (k == 0) return {a[i], 0};
        return {0, a[i]};
    }
    if (dp[i][j][k].first != 1e18) return dp[i][j][k];
    dp[i][j][k] = {0, 0};
    auto t1 = rec(i+1, j, !k);
    auto t2 = rec(i, j-1, !k);
    if (k == 0)
    {
        if (t1.first + a[i] >= t2.first + a[j]) dp[i][j][k] = {t1.first + a[i], t1.second}; 
        else dp[i][j][k] = {t2.first + a[j], t2.second};
    }
    else
    {
        if (t1.second + a[i] >= t2.second + a[j]) dp[i][j][k] = {t1.first, t1.second + a[i]}; 
        else dp[i][j][k] = {t2.first, t2.second + a[j]};
    }
    return dp[i][j][k];
}

void solve()
{
    cin >> n;
    a = vector<ll>(n);
    for (auto &e : a) cin >> e;
    for (ll i = 0; i < n; i++)
        for (ll j = i; j < n; j++)
            dp[i][j][0] = dp[i][j][1] = {1e18, 1e18};
    cout << rec(0, n-1, 0).first << '\n';
}
/* main funciton */
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return (0);
}
