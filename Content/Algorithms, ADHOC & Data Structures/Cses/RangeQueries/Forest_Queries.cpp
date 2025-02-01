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
vector<ll> a[1001];
vector<ll> seg[4001];

ll getSizeLowerThan(vector<ll> &arr, ll v)
{
    ll left = 0, right = int(arr.size()) - 1, mid, res = -1;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] <= v)
        {
            res = mid + 1;
            left = mid + 1;
        }
        else right = mid - 1;
    }
    if (res == -1) return (0);
    return (res);
}

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
    merge(seg[cur*2+1].begin(), seg[cur*2+1].end(), seg[cur*2+2].begin(), seg[cur*2+2].end(), std::back_inserter(seg[cur]));
}

ll query(ll ql, ll qr, ll a, ll b, ll left, ll right, ll cur)
{
    if (ql <= left && right <= qr) return (getSizeLowerThan(seg[cur], b) - getSizeLowerThan(seg[cur], a - 1));
    if (left > qr || ql > right) return (0);
    ll mid = left + (right - left) / 2;
    return (
        query(ql, qr, a, b, left, mid, cur*2+1)
        +  query(ql, qr, a, b, mid+1, right, cur*2+2)
    );
}

void solve()
{
    ll n, q; cin >> n >> q;
    for (ll i = 0; i < n; i++)
    {
        string r; cin >> r;
        for (ll j = 0; j < n; j++)
            if (r[j] == '*') a[i].push_back(j);
    }
    setup(0, n-1, 0);
    while (q--)
    {
        ll y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1 -= 1, x1 -= 1, y2 -= 1, x2 -= 1;
        cout << query(y1, y2, x1, x2, 0, n-1, 0) << '\n';
    }
}
/* main funciton */
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return (0);
}
