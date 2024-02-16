/*
!!!! not completed Yet.
*/
# include "header.hpp"
struct BigInt
{
	vector<int> a;
	BigInt(string &s)
	{
		a.resize(s.size());
		for (int i = 0; i < s.size(); i++) a[i]=s[i]-'0';
	}
	BigInt(const BigInt &other)
	{
		this->a = other.a;
	}
	BigInt operator+(BigInt &other)
	{
		return *this;
	}
	BigInt operator*(BigInt &other)
	{
		vector< vector<int> >	table(other.a.size(),
				vector<int>
					(
						this->a.size() + other.a.size() + 1,
						0
					)
				);
		for (int i = (other.a.size()-1), j = 0; i >= 0; i--, j++)
			for (int k = (table[j].size()-1-j), p = (this->a.size()-1); p >= 0; k--, p--)
			{
				table[j][k] += (this->a[p]*other.a[i]);
				table[j][k-1] += (table[j][k])/10;
				table[j][k] %= 10;
			}
		vector<int> res(table[0].size());
		for (int j = table[0].size()-1; j > 0; j--)
		{
			for (int i = table.size()-1; i >= 0; i--) res[j] += table[i][j];
			res[j-1] = res[j]/10;
			res[j] %= 10;
		}
		string x = "";
		int c = 0;
		while ((c < res.size()) && res[c]==0) c++;
		for (; c < res.size(); c++) x += res[c]+'0';
		return BigInt(x);
	}
};
bool operator<(const BigInt &a, const BigInt &b)
{
	if (a.a.size() != b.a.size()) return (a.a.size() < b.a.size());
	for (int i = 0; i < a.a.size(); i++)
		if (a.a[i] != b.a[i]) return (a.a[i] < b.a[i]);
	return (false);
}
ostream &operator<<(ostream &os, const BigInt &num)
{
	for (int i = 0; i < num.a.size(); i++) os << num.a[i];
	return (os);
}
