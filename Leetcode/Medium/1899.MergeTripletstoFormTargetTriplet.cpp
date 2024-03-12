/*
1899. Merge Triplets to Form Target Triplet

Medium

link to the problem:
https://leetcode.com/problems/merge-triplets-to-form-target-triplet
*/
class Solution {
public:
	bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target)
	{
		vector<int> cur(3, 0);

		for (auto &t : triplets)
		{
			bool valid = true;
			for (int i = 0; i < 3; i++)
				if (target[i] < t[i]) valid = false;
			if (valid)
				for (int i = 0; i < 3; i++)
					cur[i] = max(cur[i], t[i]);
		}

		return (cur == target);
	}
};
