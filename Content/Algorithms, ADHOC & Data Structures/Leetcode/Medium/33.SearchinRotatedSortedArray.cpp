/*
33. Search in Rotated Sorted Array

Medium

link to the problem:
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/
class Solution
{
public:
	int search(vector<int>& nums, int target) {

		int n = nums.size();
		int start = 0;
		int end = n - 1;
		int mid, res = -1;

		while (start <= end)
		{
			mid = start + (end - start) / 2;

			if (nums[mid] == target)
			{
				res = mid;
				break ;
			}

			if (nums[mid] >= nums.front())
			{
				if (target < nums[mid] && target >= nums.front())
				{
					end = mid - 1;
				}
				else
				{
					start = mid + 1;
				}
			}
			else
			{
				if (target > nums[mid] && target <= nums.back())
				{
					start = mid + 1;
				}
				else
				{
					end = mid - 1;
				}
			}
		}

		return (res);
	}
};
