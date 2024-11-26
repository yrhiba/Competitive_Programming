#include "header.hpp"

vector<int> suffixArray(string &s)
{
	/*
		suffix Array implementation;
		algorithm idea - ressources: https://codeforces.com/edu/course/2/lesson/2/1
	*/

	// special Cases no need to run the algorithm for them
	if (s.empty()) return vector<int>{0};
	if (s.size() == 1) return vector<int>{1, 0};

	// starting of the algorithms steps
	s += '$';

	int n = int(s.size()), k = 0;
	for (; (1ll<<k) < n; k++);

	vector<vector<int>> eqClass(n, vector<int>(k+1));

	// first step k = 0
	{
		vector<pair<char, int>> t(n);
		for (int i = 0; i < n; i++) {
			t[i] = {s[i], i};
		}
		sort(t.begin(), t.end());
		for (int i = 0, idx = -1; i < n; i++) {
			if (!i || t[i].first != t[i-1].first) {
				eqClass[t[i].second][0] = ++idx;
			} else {
				eqClass[t[i].second][0] = eqClass[t[i-1].second][0];
			}
		}
	}

	vector<vector<int>> t(n);

	// second step k:1 -> 2^k >= n
	for (int i = 1; i <= k; i++) {
		int incr = 1ll<<(i-1);
		for (int j = 0; j < n; j++) {
			t[j] = {eqClass[j][i-1], eqClass[(j+incr) % n][i-1], j};
		}
		sort(t.begin(), t.end());
		for (int j = 0, idx = -1; j < n; j++) {
			if (!j || t[j][0] != t[j-1][0] || t[j][1] != t[j-1][1]) {
				eqClass[t[j][2]][i] = ++idx;
			} else {
				eqClass[t[j][2]][i] = eqClass[t[j-1][2]][i];
			}
		}
	}

	// 
	vector<int> res(n);
	for (int i = 0; i < n; i++) {
		res[i] = t[i][2];
	}

	// remove the special added charachter
	s.pop_back();

	return (res);
}
