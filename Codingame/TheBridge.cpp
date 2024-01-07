/*

Puzzles Classic puzzle - Hard 

The Bridge

Difficulty : Hard

Community success rate: 25%

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector<string> actions = {
	"SPEED",
	"SLOW",
	"JUMP",
	"WAIT",
	"UP",
	"DOWN"
};
int m, v, s;
vector< pair<vector<string>, int> > moves;
vector<string> cur;
vector< vector<int> > motors;
vector<string> g;
bool ans = false;

void dfs()
{
	if (cur.size() > 50 || ans)
		return ;

	int remainingMotors = 0, reachTheEnd = false;
	for (auto &motor:motors)
	{  
		remainingMotors += motor.back();
		if (motor[0] >= g[0].size()) reachTheEnd = true;
	}
	if (remainingMotors < v) return ;
	if (reachTheEnd)
	{
		ans = true;
		moves.push_back({cur, remainingMotors});
		return ;
	}

	vector< vector<int> >	curMotors = motors;
	int						curS = s;

	for (string action:actions)
	{
		cur.push_back(action);

		motors = curMotors;
		s = curS;

		if (action=="SPEED" || action=="SLOW" || action=="WAIT")
		{
			s += ((action=="SPEED") ? 1 : ((action=="SLOW") ? -1 : 0));
			if (s <= 0) {
				cur.pop_back();
				continue ;
			}
			for (auto &motor:motors)
			{
				if (!(motor[2])) continue;
				for (int i = 0; i < s; i++)
					if (g[motor[1]][++(motor[0])]=='0')
					{
						motor[2] = 0;
						break;
					}
			}
		}
		else if (action=="JUMP")
		{
			for (auto &motor:motors)
			{
				if (!motor[2]) continue;
				motor[0] += s;
				if (g[motor[1]][motor[0]] == '0') motor[2] = 0;
			}
		}
		else if (action=="UP" || action=="DOWN")
		{
			int x = (action=="DOWN")?+1:-1;
			bool can = true;
			for (auto &motor:motors)
			{
				if (!motor[2]) continue;
				if ((motor[1] + x) < 0 || (motor[1] + x) > 3)
				{
					can = false;
					break;
				}
				for (int i = 0; i < s; i++)
				{
					motor[0] += 1;
					if ((g[motor[1] + x][motor[0]] == '0') || (i+1 < s && g[motor[1]][motor[0]] == '0'))
					{
						motor[2] = 0;
						break ;
					}
				}
				motor[1] += x;
			}
			if (!can)
			{
				cur.pop_back();
				continue;
			}
		}

		dfs();
		cur.pop_back();
	}
}

int main()
{
	cin >> m >> v; cin.ignore();
	g.resize(4);
	for (string &r:g)
		cin>>r;
	motors.resize(m);
	for (auto&motor:motors) motor=vector<int>(3);

	int turn = 0, ac = 0;
	while (true)
	{
		cin >> s; cin.ignore();
		for (int i = 0; i < m; i++)
			for (int j = 0; j < 3; j++) cin >> motors[i][j];

		if (turn == 0)
		{
			dfs();
		}
		
		if (turn < moves[0].first.size())
		{
			cout << moves[0].first[turn] << endl;
		}
		else
		{
			cout << "WAIT" << endl;
		}

		turn += 1;
	}
	return (0);
}
