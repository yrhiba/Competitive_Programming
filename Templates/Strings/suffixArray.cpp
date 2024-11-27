#include "header.hpp"

struct SuffixArray
{
	string s; // the string s
	vector<int> sfxArr; // sfx array
	vector<int> LCP; // store the longest comman prefix between sfxArr[i], sfxArr[i+1]
	vector<int> sfxMap; // get suffix index in the sfx Array

	SuffixArray(const string &_s) : s(_s)
	{
		/*
			suffix Array implementation;
			source algorithm idea:
			https://codeforces.com/edu/course/2/lesson/2/1
		*/

		// special Cases no need to run the algorithm for them
		if (s.empty()) {
			sfxArr = vector<int>{0};
			return ;
		}
		//
		if (s.size() == 1) {
			sfxArr = vector<int>{1, 0};
			return ;
		}

		// starting of the algorithms steps
		s += '$';

		int n = int(s.size()), k = 0;
		for (; (1ll<<k) < n; k++);

		vector<int> eqClass(n);
		sfxArr = vector<int>(n);

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
				sfxArr[i] = t[i].second;
			}
		}

		vector<vector<int>> t(n);
		vector<vector<int>> cnt(n);

		// second step k:1 -> 2^k >= n
		for (int i = 1; i <= k; i++) {
			int incr = 1ll<<(i-1);
			for (int j = 0; j < n; j++) {
				cnt[eqClass[(sfxArr[j] - incr + n) % n]].push_back(sfxArr[j]);
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
				sfxArr[j] = t[j][2];
			}
		}

		// remove the special added charachter
		s.pop_back();
	}

	void buildSfxMap()
	{
		assert(!sfxArr.empty());
		sfxMap = vector<int>(sfxArr.size());
		for (int i = 0; i < int(sfxArr.size()); i++) {
			sfxMap[sfxArr[i]] = i;
		}
	}

	void buildLcpArray()
	{
		this->buildSfxMap();
		int n = int(s.size());
		LCP = vector<int>(n, 0);
		for (int i = 0, k = 0; i < n; i++) {
			int idxSfx1 = sfxArr[sfxMap[i]];
			int idxSfx2 = sfxArr[sfxMap[i] - 1];
			while ((idxSfx1 + k) < int(s.size())
				&& (idxSfx2 + k) < int(s.size())
				&& s[idxSfx1 + k] == s[idxSfx2 + k]) k += 1;
			LCP[sfxMap[i] - 1] = k;
			if (k) k -= 1;
		}
	}
};
