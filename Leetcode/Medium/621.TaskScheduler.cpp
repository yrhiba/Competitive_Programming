/*
Topics : greedy - Max-Heap - queue
link to the problem:
https://leetcode.com/problems/task-scheduler
*/
class Solution {
public:
	int leastInterval(vector<char>& tasks, int n)
	{
		vector<int> letters_cnt(26, 0);
		//
		for (char c : tasks) letters_cnt[c - 'A'] += 1;
		//
		priority_queue<pair<int, char>> pr;
		//
		for (char c = 'A'; c <= 'Z'; c++)
			if (letters_cnt[c - 'A']) pr.push({letters_cnt[c - 'A'], c});
		//
		int cycle = 0;
		//
		queue<pair<char, int>>  q;
		//
		while (!q.empty() || !pr.empty())
		{
			cycle += 1;
			//
			if (!pr.empty())
			{
				char c = pr.top().second;
				//
				letters_cnt[c - 'A'] -= 1;
				//
				pr.pop();
				//
				if (letters_cnt[c - 'A']) q.push({c, cycle + n});
			}
			else cycle = max(cycle, q.front().second);
			//
			if (!q.empty() && q.front().second <= cycle)
			{
				char c = q.front().first;
				pr.push({letters_cnt[c - 'A'], c});
				q.pop();
			}
		}
		//
		return (cycle);
	}
};
