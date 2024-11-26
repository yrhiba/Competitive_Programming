#include "header.hpp"

/*
	res = empty vector where the answer got stored
*/
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
		sort(t.begin(), t.end());
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
