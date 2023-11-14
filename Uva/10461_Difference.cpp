/*

10461 - Difference

link to the problem:
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1402

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
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}
ll gcd(ll a, ll b)
{
	if (b == 0) return (a);
	return (gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a, b));
}

ll calcBfs(const vector<ll> &time, const vector< vector<ll> > &g, ll job_asking_about)
{
	ll ans = 0;

	vector< bool > visited(time.size(), false);

	visited[job_asking_about] = true;

	queue<ll> qj;	qj.push(job_asking_about);

	while (qj.size())
	{
		ll cur_job = qj.front(); qj.pop();

		ans += time[cur_job];

		for (ll job : g[cur_job])
		{
			if (visited[job]) continue;

			visited[job] = true;
			qj.push(job);
		}
	}
	return (ans);
}

void solve(ll v, ll e)
{
	ll total_jobs_time = 0;

	// read the time for each job
	vector<ll> time(v, 0);
	for (ll i = 0; i < v; i++)
	{
		cin >> time[i];
		total_jobs_time += time[i];
	}

	// graph describe the jobs that depends on it;
	vector< vector<ll> > g(v);
	// graph describe the jobs that it's depends on it;
	vector< vector<ll> > rg(v);

	// read the edges
	for (ll i = 0; i < e; i++)
	{
		ll ja, jb;
		cin >> ja >> jb;
		ja--; jb--;

		g[ja].push_back(jb);
		rg[jb].push_back(ja);
	}

	// read the querys size;
	ll q; cin >> q;

	while (q--)
	{
		ll job_asking_about;
		cin >> job_asking_about; job_asking_about--;

		ll min_start_time = calcBfs(time, g, job_asking_about) - time[job_asking_about];
		ll max_start_time = total_jobs_time - calcBfs(time, rg, job_asking_about);

		cout << max_start_time - min_start_time << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t; t = 1;
	while (true)
	{
		ll v, e; cin >> v >> e;

		if (v == 0 && e == 0)
			break;

		cout << "Case #" << t++ << ":" << endl;
		solve(v, e);
		cout << endl;
	}
}
