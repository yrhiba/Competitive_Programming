/*
G. Unexpected Behaviour

time limit per test: 2 seconds
memory limit per test: 256 megabytes
input: standard input
output: standard output

link to the problem:
https://codeforces.com/group/e5ZwbLkcA9/contest/523900/problem/G
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <cassert>
using namespace std;
string evaluate(const string &exp);

map<string, string>	db;

string getLiteral(string &id, int start, int end)
{
	string ans = "";
	for (int i = start; i < end; i++) ans += id[i];
	return (ans);
}

pair<int, string> getIdentifier(string &id, int start, int end)
{
	string ans = "";
	while (start < end && isalpha(id[start]))
	{
		ans += id[start];
		start += 1;
	}
	return make_pair(start, ((db.find(ans) == db.end()) ? ans : db[ans]));
}

pair<int, string> execute(map<int, int> &quotesMapping, map<int, int> &bracketsMapping, string &exp, int start, int end)
{
	string curAns = "";

	while (start < end && (exp[start] == '+' || exp[start] == '*' || exp[start] == ' ')) start += 1;

	if (start >= end) return make_pair(end, curAns);

	if (exp[start] == '"')
	{
		curAns += getLiteral(exp, start + 1, quotesMapping[start]);
		return make_pair(quotesMapping[start]+1, curAns);
	}
	else if (exp[start] == '(')
	{
		curAns = evaluate(exp.substr(start+1, (bracketsMapping[start]-1)-(start+1)+1));
		return make_pair(bracketsMapping[start]+1, curAns);
	}
	else if ('1' <= exp[start] && exp[start] <= '9')
	{
		auto x = execute(quotesMapping, bracketsMapping, exp, start+1, end);
		for (int i = 0; i < (exp[start] - '0'); i++) curAns += x.second;
		start = x.first;
		return {start, curAns};
	}

	return getIdentifier(exp, start, end);
}

string evaluate(const string &exp)
{
	if (exp.empty()) return "";
	map<int, int> quotesMapping;
	map<int, int> bracketsMapping;
	string cleanedExp = "";
	for (int i = 0; i < exp.size(); i++)
	{
		if (exp[i] == ' ') continue;
		cleanedExp.push_back(exp[i]);
		if (exp[i] == '"')
		{
			i += 1;
			while (exp[i] != '"')
			{
				cleanedExp.push_back(exp[i]);
				i += 1;
			}
			cleanedExp.push_back(exp[i]);
		}
	}
	stack<int> openQuotes, openBracket;
	for (int i = 0; i < cleanedExp.size(); i++)
	{
		if (cleanedExp[i] == '(') openBracket.push(i);
		else if (cleanedExp[i] == ')')
		{
			bracketsMapping[openBracket.top()] = i;
			openBracket.pop();
		}
		else if (cleanedExp[i] == '"')
		{
			if (openQuotes.empty()) openQuotes.push(i);
			else
			{
				quotesMapping[openQuotes.top()] = i;
				openQuotes.pop();
			}
		}
	}
	//
	string globalAns = "";
	//
	for (int start = 0; start < cleanedExp.size(); )
	{
		auto x = execute(quotesMapping, bracketsMapping, cleanedExp, start, cleanedExp.size());
		start = x.first;
		if (!x.second.empty()) globalAns += x.second;
	}
	//
	return (globalAns);
}

void solve()
{
	string line;
	//
	int n; cin >> n; cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, line);
		stringstream ss(line);
		string op; ss >> op; ss.ignore();
		if (op == "get")
		{
			string identifier; ss >> identifier; ss.ignore();
			if (db.find(identifier) != db.end()) cout << db[identifier] << "\n";
			else cout << identifier << "\n";
		}
		else if (op == "set")
		{
			string identifier; ss >> identifier; ss.ignore();
			string exp; getline(ss, exp);
			db[identifier] = evaluate(exp.substr(exp.find('=') + 1, exp.size()));
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
