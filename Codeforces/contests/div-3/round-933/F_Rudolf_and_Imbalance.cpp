/*
link to the problem:
https://codeforces.com/contest/1941/problem/F
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
# define ull unsigned long long
# define ll long long
ll mod = 1e9 + 7;
using namespace std;

void solve()
{
	ll n, m, k; cin >> n >> m >> k;
	multiset<ll> problems;
	vector<ll> a(n); for (ll &i : a) cin >> i, problems.insert(i);
	vector<ll> d(m); for (ll &i : d) cin >> i;
	vector<ll> f(k); for (ll &i : f) cin >> i;
	sort(d.begin(), d.end());
	sort(f.begin(), f.end());
	//
	ll		default_ans = -1;
	bool	duplicate = false;
	pair<ll, ll> target_range = {-1, -1};
	for (ll i = 1; i < n; i++)
		if ((default_ans == -1) || (a[i] - a[i-1] >= default_ans))
		{
			if (a[i] - a[i-1] == default_ans) duplicate = true;
			else
				duplicate = false, 
				default_ans = a[i] - a[i-1],
				target_range = {a[i-1], a[i]};
		}
	//
	if (duplicate)
	{
		cout << default_ans << "\n";
		return ;
	}
	//
	ll target_value = target_range.first + (target_range.second - target_range.first) / 2;
	//
	ll	best_problem_cmplx = -1;
	//
	for (ll &model : d)
	{
		ll start = 0;
		ll end = k - 1;
		ll mid;
		//
		while (start <= end)
		{
			mid = start + (end - start) / 2;
			//
			ll cur_problem_cmplx = model + f[mid];
			//
			if ((target_range.first < cur_problem_cmplx && cur_problem_cmplx < target_range.second))
			{
				ll ans1 = max(cur_problem_cmplx - target_range.first, target_range.second - cur_problem_cmplx);
				ll ans2 = max(best_problem_cmplx - target_range.first, target_range.second - best_problem_cmplx);
				if ((best_problem_cmplx == -1) || ans1 < ans2) best_problem_cmplx = cur_problem_cmplx;
			}
			//
			if (cur_problem_cmplx < target_value) start = mid + 1;
			else end = mid - 1;
		}
	}
	//
	if (best_problem_cmplx == -1)
	{
		cout << default_ans << "\n";
		return ;
	}
	//
	problems.insert(best_problem_cmplx);
	a = vector<ll>(problems.begin(), problems.end());
	n = a.size();
	ll ans = -1;
	for (ll i = 1; i < n; i++)
		if (ans == -1 || a[i] - a[i-1] > ans) ans = a[i] - a[i - 1];
	//
	cout << ans << '\n';
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	ll t; cin >> t;
	while (t--)
		solve();
}
