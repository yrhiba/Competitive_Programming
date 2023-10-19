/*
name: 10305 Ordering Tasks
link to the problem:
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1246
link to the problem (pdf format):
https://onlinejudge.org/external/103/10305.pdf
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

void dfs(ll task, vector<bool> &exucuted_tasks, vector< vector<ll> > &graph, vector<ll> &ans)
{
	for (ll i = 0; i < graph[task].size(); i++)
	{
		if (exucuted_tasks[graph[task][i]] || (task == graph[task][i])) continue;
		dfs(graph[task][i], exucuted_tasks, graph, ans);
	}
	exucuted_tasks[task] = true;
	ans.push_back(task);
}

void solve(ll n, ll m)
{
	vector< vector<ll> > graph(n+1, vector<ll>(1, 0));

	for (ll x = 0; x < m; x++)
	{
		ll i, j;
		cin >> i >> j;

		graph[j].push_back(i);
	}

	vector< bool > exucuted_tasks(n+1, false);

	exucuted_tasks[0] = true;

	vector<ll> ans; ans.reserve(n);

	for (ll i = 0; i <= n; i++)
	{
		if (exucuted_tasks[i]) continue;
		dfs(i, exucuted_tasks, graph, ans);
	}

	for (ll i = 0; i < n; i++)
	{
		cout << ans[i];
		if (i+1 < n)
			cout << " ";
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true)
	{
		ll n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		solve(n, m);
	}
}
