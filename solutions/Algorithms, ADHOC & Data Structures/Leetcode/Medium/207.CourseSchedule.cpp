/*
207. Course Schedule

Medium

link to the problem:
https://leetcode.com/problems/course-schedule/
*/
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		vector< vector<int> > g(numCourses); 
		//
		vector<int> have(numCourses, 0);
		//
		for (auto &v : prerequisites) g[v[1]].push_back(v[0]), have[v[0]] += 1;
		//
		priority_queue<int> pr;
		for (int i = 0; i < numCourses; i++) if (!have[i]) pr.push(i);
		//
		vector<int> ans;
		//
		while (!pr.empty())
		{
			int cur = pr.top();
			//
			pr.pop(), ans.push_back(cur);
			//
			for (int i : g[cur])
			{
				if (have[i] <= 0) continue;
				//
				have[i] -= 1;
				if (have[i] == 0) pr.push(i);
			}
		}
		//
		return (ans.size() == numCourses);
	}
};
