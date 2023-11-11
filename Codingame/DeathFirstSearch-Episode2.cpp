/*

Death First Search - Episode 2

link to the problem:
https://www.codingame.com/training/hard/death-first-search-episode-2

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#include <map>
#include <set>
#include <queue>

int main()
{
	int n; // the total number of nodes in the level, including the gateways
	int l; // the number of links
	int e; // the number of exit gateways
	cin >> n >> l >> e; cin.ignore();

	map< int, set<int> > g;
	map< int, set<int> > to_exit;

	for (int i = 0; i < l; i++) {
		int n1; // N1 and N2 defines a link between these nodes
		int n2;
		cin >> n1 >> n2; cin.ignore();

		// n1 -> n2
		g[n1].insert(n2);
		g[n2].insert(n1);
	}

	set< int > exits;

	for (int i = 0; i < e; i++) {
		int ei; // the index of a gateway node
		cin >> ei; cin.ignore();

		exits.insert(ei);
	}


	for (auto &[i, j] : g)
	{
		for (auto &x : j)
		{
			if (exits.count(x))
				to_exit[i].insert(x);
		}
	}


	// game loop
	while (1) {

		int si; // The index of the node on which the Bobnet agent is positioned this turn
		cin >> si; cin.ignore();

		queue<int> que; que.push(si);
		queue<int> par; par.push(-1);
		queue<int> m; m.push(0);

		vector<bool> visited(n+1, false); visited[si] = true;

		map< int, set<int> > mp;

		int ff = -1, ss = -1;

		while (que.size())
		{
			int &cur_node = que.front();
			int &cur_moves = m.front();

			if (to_exit[cur_node].size() > 1)
			{
				ff = cur_node;
				ss = *to_exit[cur_node].begin();
				break;
			}
			else if (to_exit[cur_node].size() == 1)
			{
				if (ff == -1)
				{
					ff = cur_node;
					ss = *to_exit[cur_node].begin();
					if (cur_moves == 0) break ;
				}

				for (auto &node : g[cur_node])
				{
					if (visited[node]) continue ;
					if (exits.count(node)) continue;
					visited[node] = true;
					que.push(node);
					m.push(cur_moves + 1);
				}
			}
			else if (ff == -1)
			{
				for (auto &node : g[cur_node])
				{
					if (visited[node]) continue ;
					if (exits.count(node)) continue;

					visited[node] = true;
					que.push(node);
					m.push(cur_moves + 1);
				}
			}

			que.pop();
			par.pop();
			m.pop();
		}

		cout << ff << " " << ss << endl;

		to_exit[ff].erase(ss);
		g[ff].erase(ss);
		g[ss].erase(ff);
	}
}