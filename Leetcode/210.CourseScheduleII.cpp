/*
210. Course Schedule II

Medium

link to the problem:
https://leetcode.com/problems/course-schedule-ii/
*/
class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
	{
		vector<int> ans;
		vector<vector<int>> g(numCourses);
		vector<int> have(numCourses, 0);
		for (auto &v : prerequisites) g[v[1]].push_back(v[0]), have[v[0]] += 1;
		queue<int> q;
		for (int i = 0; i < numCourses; i++) if (!have[i]) q.push(i);
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			ans.push_back(cur);
			for (int i : g[cur])
			{
				if (!have[i]) continue;
				have[i] -= 1;
				if (!have[i]) q.push(i);
			}
		}
		if (ans.size() != numCourses) return vector<int>();
		return ans;
	}
};
