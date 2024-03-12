/*

Codeforces Round 915 (Div. 2)

C. Largest Subsequence

link to the problem:
https://codeforces.com/contest/1905/problem/C

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
	ll n; cin >> n;
	string s; cin >> s;
	string r = s;
	sort(r.begin(), r.end());

	vector<ll> f(n);
	int max_c = n-1;
	for (int i= n-1; i>=0; i--)
	{
		if (s[i] >= s[max_c])
			max_c = i;
		f[i] = max_c;
	}

	vector< bool > x(n, false);

	string ans;
	for (int i = 0; i < n; i++)
		x[f[i]] = true;

	for (int i = 0; i < n; i++)
		if (x[i])
			ans += s[i];

	reverse(ans.begin(), ans.end());

	for (ll i = 0, k = 0; i < n; i++)
	{
		if (x[i])
		{
			s[i] = ans[k];
			k++;
		}
	}

	if (s != r)
	{
		cout << -1 << "\n";
	}
	else
	{
		for (ll i = ans.size() - 1; i>0; i--)
		{
			if (ans[i] != ans[i - 1])
				break;
			ans.pop_back();
		}
		cout << ans.size() - 1 << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)
		solve();
}