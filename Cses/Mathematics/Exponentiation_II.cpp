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

/* solution */
ll powermod(ll x, ll p, ll m = mod)
{
    if (p == 0) return (1);
    ll res = powermod(x, p/2, m) % m;
    if (p%2)
        return ((((res * res) % m) * (x % m)) % m);
    return ((res * res) % m);
}
void solve()
{
    ll a, b, c; cin >> a >> b >> c;
    ll bc = powermod(b, c, mod - 1);
    ll abc = powermod(a, bc);
    cout << abc << '\n';
}
/* main funciton */
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll t; cin >> t;
    while (t--)
        solve();   
    return (0);
}
