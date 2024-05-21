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
# define ll int
ll mod = int(1e9 + 7);
using namespace std;

struct Node
{
	map<pair<char, bool>, Node*> links;
	int endOf;
	//
	Node ()
	{
		this->endOf = 0;
	}
};

struct Trie
{
	Node *root;
	Trie() { root = new Node(); }
};

int rec(const int &n, vector<set<int>> &graph, vector<int> &dp, int cur)
{
	if (cur == n) return (1);
	if (dp[cur] != -1) return (dp[cur]);

	dp[cur] = 0;

	for (int nxt : graph[cur])
	{
		dp[cur] += rec(n, graph, dp, nxt);
		dp[cur] %= mod;
	}

	return dp[cur];
}

void solve()
{
	Trie trie;
	//
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		Node *it = trie.root;
		string s; cin >> s;
		//
		s.push_back('$');
		//
		for (int i = 0; i+1 < int(s.size()); i++)
		{
			if (it->links.find({s[i], (s[i+1] == '+')}) == it->links.end())
			{
				it->links[{s[i], (s[i+1] == '+')}] = new Node();
			}
			//
			it = it->links[{s[i], (s[i+1] == '+')}];
			//
			if (s[i+1] == '+') i += 1;
		}
		//
		it->endOf += 1;
	}
	//
	string t; cin >> t;
	n = t.size();
	//
	vector<set<int>> graph(n);
	//
	for (int i = 0; i < n; i++)
	{
		queue<pair<Node *, bool>> q;
		q.push({trie.root, false});

		for (int j = i; j < n; j++)
		{
			queue<pair<Node*, bool>> nexts;

			while (!q.empty())
			{
				Node *it = q.front().first;
				bool extend = q.front().second;
				q.pop();

				if (extend && (j != i) && (t[j] == t[j-1]))
				{
					nexts.push({it, true});
					if (it->endOf) graph[i].insert(j+1);
				}

				if (it->links[{t[j], true}])
				{
					nexts.push({it->links[{t[j], true}], true});
					if (it->links[{t[j], true}]->endOf) graph[i].insert(j+1);
				}

				if (it->links[{t[j], false}])
				{
					nexts.push({it->links[{t[j], false}], false});
					if (it->links[{t[j], false}]->endOf) graph[i].insert(j+1);
				}
			}

			if (nexts.empty()) break;
			q = nexts;
		}
	}
	//
	vector<int> dp(n, -1);
	cout << rec(n, graph, dp, 0) << "\n";
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
