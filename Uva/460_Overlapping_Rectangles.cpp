/*

460 Overlapping Rectangles

link to the problem:
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=401

link to the problem (pdf version):
https://onlinejudge.org/external/4/460.pdf

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

void solve()
{

	ll xmin1, xmax1, xmin2, xmax2;
	ll ymin1, ymax1, ymin2, ymax2;


	cin >> xmin1 >> ymin1 >> xmax1 >> ymax1;
	cin >> xmin2 >> ymin2 >> xmax2 >> ymax2;

	bool overlap_x = false, overlap_y = false;

	ll res_xmin, res_ymin, res_xmax, res_ymax;

	if (xmin1 <= xmin2 && xmin2 <= xmax1)
	{
		res_xmin = xmin2;
		res_xmax = min(xmax1, xmax2);

		overlap_x = true;
	}
	else if (xmin2 <= xmin1 && xmin1 <= xmax2)
	{
		res_xmin = xmin1;
		res_xmax = min(xmax1, xmax2);

		overlap_x = true;
	}

	if (ymin1 <= ymin2 && ymin2 <= ymax1)
	{
		res_ymin = ymin2;
		res_ymax = min(ymax1, ymax2);

		overlap_y = true;
	}
	else if (ymin2 <= ymin1 && ymin1 <= ymax2)
	{
		res_ymin = ymin1;
		res_ymax = min(ymax1, ymax2);

		overlap_y = true;
	}

	if (overlap_x && overlap_y && (res_xmin != res_xmax && res_ymin != res_ymax))
	{
		if (res_xmin > res_xmax)
			swap(res_xmin, res_xmax);

		if (res_ymin > res_ymax)
			swap(res_ymin, res_ymax);

		cout << res_xmin << " " << res_ymin << " " << res_xmax << " " << res_ymax << "\n";
	}
	else
	{
		cout << "No Overlap\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	for (ll i = 0; i < t; i++)
	{
		if (i)
			cout << "\n";
		solve();
	}
}
