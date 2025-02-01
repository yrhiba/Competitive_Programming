/*
CSES Problem Set

Movie Festival II

link to the problem:
https://cses.fi/problemset/task/1632/
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
	ll n, k, ans = 0; cin >> n >> k;
	vector<pair<ll, ll>> a(n);
	for (auto &[end, start] : a) cin >> start >> end;
	sort(a.begin(), a.end());
	multiset<ll, greater<ll>> memebers;
	for (auto &[end, start] : a)
	{
		auto prvM = memebers.lower_bound(start);
		//
		if (prvM == memebers.end())
		{
			if (memebers.size() < k) ans += 1, memebers.insert(end);
		}
		else
		{
			ans += 1;
			memebers.erase(prvM);
			memebers.insert(end);
		}
	}
	//
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
