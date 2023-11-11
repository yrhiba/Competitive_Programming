/*

HARD CODINGAME PROBLEM.

The greatest number

link to the problem:
https://www.codingame.com/training/hard/the-greatest-number

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n; cin.ignore();

	bool is_neg, is_with_dot; is_neg = is_with_dot = false;

	vector< char > nums;

	for (int i = 0; i < n; i++)
	{
		char c; cin >> c;

		if (c == '.')
		{
			is_with_dot = true;
		}
		else if (c == '-')
		{
			is_neg  = true;
		}
		else
			nums.push_back(c);
	}


	if (is_neg)
	{
		sort(nums.begin(), nums.end());

		if (is_with_dot)
		{
			int i = nums.size() - 1;
			while (i > 0 && nums[i] == '0')
			{
				nums.pop_back();
				i--;
			}

			if (nums.size() == 1 && nums[0] == '0')
			{
				cout << "0" << endl;
			}
			else
			{
				cout << "-";
				i = 0;
				cout << nums[i] << ".";
				while (++i < nums.size())
					cout << nums[i];
				cout << endl;
			}

		}
		else
		{
			int i = 0;
			while (i < nums.size() && nums[i] == '0')
				i++;
			if (i >= nums.size())
			{
				cout << "0" << endl;
			}
			else
			{
				cout << "-";
				while (i < nums.size())
					cout << nums[i++];
				cout << endl;
			}
		}
	}
	else
	{
		sort(nums.rbegin(), nums.rend());

		if (is_with_dot)
		{
			if (nums.front() == '0')
			{
				cout << "0" << endl;
			}
			else
			{
				for (int i = 0; i+1 < nums.size(); i++)
					cout << nums[i];
				if (nums.back() == '0')
				{
					cout << endl;
				}
				else
				{
					cout << '.' << nums.back() << endl;
				}
			}
		}
		else
		{
			int i = 0;
			while (i < nums.size() && nums[i] == '0')
				i++;

			if (i >= nums.size())
			{
				cout << 0 << endl;
			}
			else
			{
				while (i < nums.size())
					cout << nums[i++];
				cout << endl;
			}
		}
	}
}