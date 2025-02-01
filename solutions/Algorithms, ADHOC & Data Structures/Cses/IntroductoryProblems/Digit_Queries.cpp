/*
CSES Problem Set

Digit Queries

link to the problem:
https://cses.fi/problemset/task/2431
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

ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}

ll log10(ll n)
{
	if (!n) return (1);
	//
	ll lg = 0;
	while (n)
	{
		lg += 1;
		n /= 10;
	}
	//
	return lg;
}

ll getDigit(ll n, ll idx)
{
	if (!n) return (0);
	string _n;
	while (n)
	{
		_n.push_back(n%10 + '0');
		n /= 10;
	}
	reverse(_n.begin(), _n.end());
	//
	if (idx < 0 || idx > _n.size()) return (-1);
	return _n[idx - 1] - '0';
}

ll countDigitBeforeK(ll n)
{
	if (n <= 9) return (n - 1);
	//
	ll digitLen = log10(n), digitBeforKResult = 0;
	//
	for (ll i = 0; i < (digitLen - 1); i++) digitBeforKResult += 9 * power(10, i) * (i + 1);
	//
	return digitBeforKResult + ((n - power(10, digitLen - 1)) * digitLen);
}

void solve()
{
	ll k; cin >> k;

	ll left = 1;
	ll right = 1e18;
	ll mid;

	while (left <= right)
	{
		mid = left + (right - left) / 2;

		ll digitsCountBeforeK = countDigitBeforeK(mid);

		if (digitsCountBeforeK < k && k <= (digitsCountBeforeK + log10(mid)))
		{
			cout << getDigit(mid, (k - digitsCountBeforeK)) << "\n";
			return ;
		}
		else if (digitsCountBeforeK >= k) right = mid - 1;
		else left = mid + 1;
	}
	//
	cout << "\n-1\n";
	return ;
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
