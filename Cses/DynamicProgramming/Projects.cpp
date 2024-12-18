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
# define ll long long
 
/* global varibles */
 
void solve()
{
    ll n; cin >> n;
    vector<vector<ll>> a(n, vector<ll>(4));
    vector<vector<ll>> e(n*2);
    for (ll i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        e[i] = {a[i][0], i, 0};
        e[i+n] = {a[i][1], i, 1};
    }
    sort(all(e));
    ll idx = 0;
    for (ll i = 0; i < int(e.size()); i++) {
        if (!(i && (e[i][0] == e[i-1][0]))) idx += 1;
        a[e[i][1]][e[i][2]] = idx;
    }
    vector<vector<pair<ll, ll>>> ends(idx+1);
    for (ll i = 0; i < n; i++) {
        ends[a[i][1]].push_back({a[i][0], a[i][2]});
    }
    vector<ll> dp(idx+1, -1);
    dp[0] = 0;
    ll ans = 0;
    for (ll i = 1; i <= idx; i++) {
        dp[i] = max(dp[i], dp[i-1]);
        for (auto &[start, p] : ends[i]) {
            dp[i] = max(dp[i], dp[start - 1] + p);
        }
        ans = max(ans, dp[i]);
    }  
    cout << ans << '\n';
}
 
/* main funciton */
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return (0);
}
