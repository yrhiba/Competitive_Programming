/*
4. Median of Two Sorted Arrays

Solved

Hard

link to the problem:
https://leetcode.com/problems/median-of-two-sorted-arrays/
*/

class Solution
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		int n = nums1.size();
		int m = nums2.size();

		if (!n || !m)
		{
			if (n)
			{
				if (n%2)
					return (nums1[n/2]);
				return ((nums1[n/2 - 1] + nums1[n/2]) * .5);
			}
			else
			{
				if (m%2)
					return (nums2[m/2]);
				return ((nums2[m/2 - 1] + nums2[m/2]) * .5);
			}
		}

		int len = (n + m + 1)/2;

		int start = 0;
		int end = n;
		int mid1, mid2, ans = -1;

		while (start <= end)
		{
			mid1 = (start + end) / 2;
			mid2 = len - mid1;


			if (mid2 < 0)
			{
				end = mid1 - 1;
				continue;
			}

			if (mid2 > m)
			{
				start = mid1 + 1;
				continue;
			}

			if (mid1 < n && mid2 && nums1[mid1] < nums2[mid2 - 1])
			{
				start = mid1 + 1;
				continue;
			}

			if (mid2 < m && mid1 && nums2[mid2] < nums1[mid1 - 1])
			{
				end = mid1 - 1;
				continue;
			}

			break;
		}


		int l, r;

		if (mid1 && mid2)
			l = max(nums1[mid1 - 1], nums2[mid2 - 1]);
		else
			l = mid1 ? nums1[mid1 - 1] : nums2[mid2 - 1];


		if (mid1 < n && mid2 < m)
			r = min(nums1[mid1], nums2[mid2]);
		else
			r = mid1 < n ? nums1[mid1] : nums2[mid2];

		if ((n + m) % 2)
		{
			return l;
		}
		else
		{
			return (l + r) * .5f;
		}
	}
};
