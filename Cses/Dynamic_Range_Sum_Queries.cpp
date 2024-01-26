/*
CSES Problem Set

Dynamic Range Sum Queries

link to the problem:
https://cses.fi/problemset/task/1648/
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
# define ll long long
const ll mod = 1e9 + 7;
using namespace std;

# define DEBUG 0

void buildSegTree(
	vector<ll> &a,
	vector< vector<ll> > &segTree,
	ll left, ll right, ll i = 0)
{
	segTree[i][0] = left;
	segTree[i][1] = right;

	if (left == right)
	{
		segTree[i][2] = a[left];
		return ;
	}

	ll mid = left + (right - left) / 2;

	buildSegTree(a, segTree, left, mid, i * 2 + 1);
	buildSegTree(a, segTree, mid + 1, right, i * 2 + 2);

	segTree[i][2] = segTree[i*2 + 1][2] + segTree[i*2 + 2][2];
}

void debug(vector<vector<ll>> &segTree, ll i, bool isLeft)
{
	cout << i << " [";
	cout << "shape=\"record\", ";
	cout << "label=\"{<h>" << segTree[i][0] << " - " << segTree[i][1] << "|{<l>|";
	cout << "<c> " << segTree[i][2] << " |<r>}}\"";
	cout << "]" << endl;

	if (i)
	{
		if (isLeft)
		{
			cout << (i - 1) / 2 << ":<l> -> " << i << ";" << endl;
		}
		else
		{
			cout << (i - 2) / 2 << ":<r> -> " << i << ";" << endl;
		}
	}

	if (segTree[i][0] == segTree[i][1])
		return ;

	debug(segTree, i*2 + 1, true);
	debug(segTree, i*2 + 2, false);
}

void updatePointSegTree(vector< vector<ll> > &segTree, ll cur, ll i, ll new_value)
{
	if (segTree[cur][0] == segTree[cur][1])
	{
		if (segTree[cur][0] == i)
			segTree[cur][2] = new_value;
		return ;
	}

	if (segTree[cur][0] <= i && i <= segTree[cur][1])
	{
		updatePointSegTree(segTree, cur * 2 + 1, i, new_value);
		updatePointSegTree(segTree, cur * 2 + 2, i, new_value);
		segTree[cur][2] = segTree[cur * 2 + 1][2] + segTree[cur * 2 + 2][2];
	}

	return ;
}

ll getValueOfRange(vector< vector<ll> > &segTree, ll left, ll right, ll cur = 0)
{
	if (left <= segTree[cur][0] && segTree[cur][1] <= right)
	{
		return segTree[cur][2];
	}

	if (right < segTree[cur][0] || segTree[cur][1] < left)
	{
		return (0);
	}

	return getValueOfRange(segTree, left, right, cur * 2 + 1)
		+ getValueOfRange(segTree, left, right, cur * 2 + 2);
}

void solve()
{
	ll n, q; cin >> n >> q;
	vector<ll> a(n);
	for (auto &i : a)
		cin >> i;

	vector< vector<ll> > segTree(n * 3, vector<ll>(3));

	buildSegTree(a, segTree, 0, n - 1);

	while (q--)
	{
		ll x, a, b; cin >> x >> a >> b;

		if (x == 1)
		{
			a -= 1;
			updatePointSegTree(segTree, 0, a, b);
		}
		else
		{
			a -= 1;
			b -= 1;
			cout << getValueOfRange(segTree, a, b) << endl;
		}
	}

	#if DEBUG
	freopen("graph.dot", "w", stdout);
	cout << "digraph {" << endl;
	debug(segTree, 0, false);
	cout << "}" << endl;
	fclose(stdout);
	#endif
}

int main()
{
	solve();
}
