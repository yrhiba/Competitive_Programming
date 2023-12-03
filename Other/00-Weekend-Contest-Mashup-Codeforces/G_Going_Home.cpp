/*
Weekend Contest

G. Going Home

link to the problem:
find problems.pdf
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


ll from_hh_to_ll(string h)
{
	ll ans = 0;

	ans = (((h[0] - '0')*10) + (h[1] - '0')) * 60;
	ans += (((h[3] - '0')*10) + (h[4] - '0'));

	return ans;
}

string from_ll_to_hh(ll h)
{
	ll hh = h / 60;
	ll mm = h % 60;

	string ans;

	ans = (char)((hh % 10) + '0');
	hh /= 10;
	ans = (char)((hh % 10) + '0') + ans;

	ans += ':';

	string ans2;
	ans2 = (char)((mm % 10) + '0');
	mm /= 10;
	ans2 = (char)((mm % 10) + '0') + ans2;


	return ans + ans2;
}

void solve()
{
	ll n, m; cin >> n >> m;

	string target; cin >> target;

	map<string, vector< pair< pair<string, ll>, set<ll> >  > > mp;

	for (ll i = 0; i < m; i++)
	{
		string from;
		cin >> from;

		string to;
		cin >> to;

		ll mins;
		cin >> mins;

		ll x; cin >> x;

		pair< pair<string, ll>, set<ll> > d;

		d.first.first = to;
		d.first.second = mins;

		set<ll> &times = d.second;
		for (ll i = 0; i < x; i++)
		{
			string t; cin >> t;
			times.insert(from_hh_to_ll(t));
		}

		mp[from].push_back(d);
	}

	queue<string> qc;
	qc.push("rostock");

	queue<ll> qtime;
	qtime.push(0);


	ll ans = 1e9;

	while (!qc.empty())
	{
		string cur_c = qc.front();
		ll cur_time = qtime.front();

		qc.pop();
		qtime.pop();

		if (cur_c == target)
		{
			ans = min(ans, cur_time);
			continue;
		}

		for (auto &v : mp[cur_c])
		{
			for (auto &start : v.second)
			{
				if (start >= cur_time)
				{
					qc.push(v.first.first);
					qtime.push(start + v.first.second);

					break;
				}
			}
		}
	}

	cout << from_ll_to_hh(ans) << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
