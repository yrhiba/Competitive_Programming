/*
yrhiba.github.io (c). 2022-2024
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
#include <cassert>
#include <random>
#include <sstream>
using namespace std;
# define all(x) begin(x), end(x)
typedef long long ll;

/* solution */
void suffixArray(vector<int> &res, string &s)
{
	/*
		suffix Array implementation;
		source algorithm idea:
		https://codeforces.com/edu/course/2/lesson/2/1
	*/

	// special Cases no need to run the algorithm for them
	if (s.empty()) {
		res = vector<int>{0};
		return ;
	}
	//
	if (s.size() == 1) {
		res = vector<int>{1, 0};
		return ;
	}

	// starting of the algorithms steps
	s += '$';

	int n = int(s.size()), k = 0;
	for (; (1ll<<k) < n; k++);

	vector<int> eqClass(n);
	res = vector<int>(n);

	// first step k = 0
	{
		vector<pair<char, int>> t(n);
		for (int i = 0; i < n; i++) {
			t[i] = {s[i], i};
		}
		sort(all(t));
		for (int i = 0, idx = -1; i < n; i++) {
			if (!i || t[i].first != t[i-1].first) {
				eqClass[t[i].second] = ++idx;
			} else {
				eqClass[t[i].second] = eqClass[t[i-1].second];
			}
			// initial suffix array result
			res[i] = t[i].second;
		}
	}

	vector<vector<int>> t(n);
	vector<vector<int>> cnt(n);

	// second step k:1 -> 2^k >= n
	for (int i = 1; i <= k; i++) {
		int incr = 1ll<<(i-1);
		for (int j = 0; j < n; j++) {
			cnt[eqClass[(res[j] - incr + n) % n]].push_back(res[j]);
		}
		for (int j = 0, idx = 0; j < n; j++) {
			for (int res_j : cnt[j]) {
				t[idx++] = {
						j,
						eqClass[res_j],
						(res_j - incr + n) % n
					};
			}
			cnt[j].clear();
		}
		for (int j = 0, idx = -1; j < n; j++) {
			if (!j || t[j][0] != t[j-1][0] || t[j][1] != t[j-1][1]) {
				eqClass[t[j][2]] = ++idx;
			} else {
				eqClass[t[j][2]] = eqClass[t[j-1][2]];
			}
			// update the result suffix array
			res[j] = t[j][2];
		}
	}

	// remove the special added charachter
	s.pop_back();
}


// -1: s1 < s2, 0: s1 == s2, 1 s1 == s2;
int cmp_str(string &t, string &s, int i, int j)
{
	while (i < t.size() && j < s.size() && t[i] == s[j])
		i += 1, j += 1;


	if (j == s.size()) {
		return (0);
	}

	if (t[i] <= s[j]) {
		return (-1);
	} else {
		return (1);
	}
}

void solve()
{
	string t; cin >> t;

	vector<int> sfxArr;
	suffixArray(sfxArr, t);

	int n = 1;

	while (n--)
	{
		string s; cin >> s;

		int L = int(sfxArr.size()), R = int(sfxArr.size());

		{
			int left = 0, right = int(sfxArr.size() - 1), mid;
			while (left <= right)
			{
				mid = left + (right - left) / 2;
				//
				int r = cmp_str(t, s, sfxArr[mid], 0);

				if (r < 0) {
					left = mid + 1;
				} else {
					if (r == 0) L = mid;
					right = mid - 1;
				}
			}
		}

		{
			int left = 0, right = int(sfxArr.size() - 1), mid;
			while (left <= right)
			{
				mid = left + (right - left) / 2;
				//
				int r = cmp_str(t, s, sfxArr[mid], 0);

				if (r <= 0) {
					left = mid + 1;
				} else {
					R = mid;
					right = mid - 1;
				}
			}
		}

		if (L <= R) cout << (R - L) << "\n";
		else cout << "0\n";
	}
}

/* main funciton */
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return (0);
}
