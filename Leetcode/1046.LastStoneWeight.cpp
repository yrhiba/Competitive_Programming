/*
1046. Last Stone Weight

Easy

link to the problem:
https://leetcode.com/problems/last-stone-weight
*/
class Solution {
public:
	int lastStoneWeight(vector<int>& stones)
	{
		priority_queue<int> pr(stones.begin(), stones.end());

		while (pr.size() > 1)
		{
			int y = pr.top(); pr.pop();
			int x = pr.top(); pr.pop();
			if (y == x) continue;
			pr.push(y - x);
		}

		return (pr.empty() ? 0 : pr.top());
	}
};
