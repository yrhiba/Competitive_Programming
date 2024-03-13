/*
CSES Problem Set

Stick Lengths

link to the problem:
https://cses.fi/problemset/task/1074
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
#include <numeric>
# define ull unsigned long long
# define ll long long
const ll mod = 1e9 + 7;
using namespace std;

void solve()
{
	ll n; cin >> n;

	ll sum = 0, mine = 1e9, maxe = -1e9;

	vector<ll> a(n);

	for (auto &i : a)
	{
		cin >> i;
		sum += i;
		mine = min(mine, i);
		maxe = max(maxe, i);
	}

	ll start = mine;
	ll end = maxe;
	ll mid, t, ans = -1;

	while (start <= end)
	{
		mid = start + (end - start) / 2;

		ll res0 = 0, res1 = 0, res2 = 0;

		for (auto &i : a)
		{
			res0 += abs(i - (mid - 1));
			res1 += abs(i - mid);
			res2 += abs(i - (mid + 1));
		}

		if (res0 >= res1 && res1 <= res2)
		{
			cout << res1 << endl;
			return ;
		}

		if (res0 <= res1 && res1 <= res2)
		{
			end = mid - 1;
		}
		else
		{
			start = mid + 1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
