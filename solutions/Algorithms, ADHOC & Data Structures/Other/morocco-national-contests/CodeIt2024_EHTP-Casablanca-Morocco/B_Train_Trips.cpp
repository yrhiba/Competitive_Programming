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
# define ll int
int mod = int(1e9 + 7);
using namespace std;

void solve()
{
	int n, d, k; cin >> n >> d >> k;

	vector<vector<int>> dp(n+1, vector<int>(k+1, 0));

	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = (1 + dp[i-1][0]) % mod;
	}

	for (int kk = 1; kk <= k; kk++)
		for (int i = 1; i <= n; i++)
		{
			//
			dp[i][kk] = dp[min(n, i + d - 1)][kk-1] - dp[max(0, i - d)][kk-1];
			dp[i][kk] %= mod;
			//
			dp[i][kk] = (dp[i][kk] - (dp[i][kk-1] - dp[i-1][kk-1]));
			dp[i][kk] %= mod;
			// //
			dp[i][kk] = (dp[i][kk] + dp[i-1][kk]) % mod;
		}

	for (int i = 1; i <= n; i++)
		cout << (dp[i][k] - dp[i-1][k] + mod) % mod << " \n"[i == n];
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while (t--)
		solve();
}
