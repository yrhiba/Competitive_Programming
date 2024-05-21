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

ll getIndex(ll q, ll left, ll right, ll cur = 0)
{
	//
	if (left == right)
	{
		if (left == q) return cur;
		return (-1);
	}
	//
	if (q < left || q > right) return (-1);
	//
	ll mid = left + (right - left) / 2;
	//
	ll i1 = getIndex(q, left, mid, cur*2+1);
	ll i2 = getIndex(q, mid+1, right, cur*2+2);
	//
	return max(i1, i2);
}

void solve()
{
	ll n, q; cin >> n >> q;

	while (q--)
	{
		ll a, b; cin >> a >> b;
		a -= 1, b -= 1;
		//
		ll idxA = getIndex(a, 0, n-1);
		ll idxB = getIndex(b, 0, n-1);
		//
		map<ll, bool> mp;
		mp[0] = true;
		//
		while (idxA)
		{
			mp[idxA] = true;
			if (idxA % 2 == 0) idxA -= 1;
			idxA /= 2;
		}
		//
		ll ans = 0;
		while (!(mp[idxB]))
		{
			ans += 1;
			if (idxB % 2 == 0) idxB -= 1;
			idxB /= 2;
		}
		//
		cout << ans << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
