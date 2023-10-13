/*
Hard Problem 42. Trapping Rain Water
link to it:
https://leetcode.com/problems/trapping-rain-water/
*/
class Solution {
public:
	int trap(vector<int>& height) {

		int max_index = 0;
		for (int i = 1; i < height.size(); i++)
			max_index = (height[i] > height[max_index]) ? i : max_index;
		
		int ans = 0, i , x, to_mins;
		
		i = 0;
		x = i + 1;
		to_mins = 0;

		while (i < max_index && x <= max_index)
		{
			while (x <= max_index && height[x] < height[i])
			{
				to_mins += height[x];
				x += 1;
			}

			ans  += (min(height[i], height[x]) * (x - i + 1 - 2) - to_mins);
			to_mins = 0;
			i = x;
			x = i + 1;
		}

		i = height.size() - 1;
		x = i - 1;
		to_mins = 0;

		while (i > max_index && x >= max_index)
		{
			while (x >= max_index && height[x] < height[i])
			{
				to_mins += height[x];
				x -= 1;
			}

			ans  += (min(height[i], height[x]) * (i - x + 1 - 2) - to_mins);
			to_mins = 0;
			i = x;
			x = i - 1;
		}

		return (ans);
	}
};