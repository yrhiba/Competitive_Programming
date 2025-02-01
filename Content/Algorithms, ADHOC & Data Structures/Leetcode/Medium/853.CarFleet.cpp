/*
853. Car Fleet

Solved

Medium

link to the problem:
https://leetcode.com/problems/car-fleet/
*/
class Solution {
public:
	int carFleet(int target, vector<int>& position, vector<int>& speed)
	{
		int n = position.size();
		vector< pair<int, int> > cars(n);
		vector< float > t(n);

		for (int i = 0; i < n; i++)
			cars[i] = {position[i], speed[i]};

		sort(cars.begin(), cars.end());

		for (int i = 0; i < n; i++)
			t[i] = ((target - cars[i].first) * 1.0f) / (cars[i].second * 1.0f);

		int ans = 1;

		for (int i = n-1; i > 0; i--)
		{
			if (t[i - 1] <= t[i])
				t[i - 1] = t[i];
			else
				ans += 1;
		}

		return (ans);
	}
};
