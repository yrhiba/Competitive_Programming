/*

Puzzles Classic puzzle - Medium 

Blunder - Episode 1

Difficulty : Medium

Community success rate: 63%

link to the problem:
https://www.codingame.com/ide/puzzle/blunder-episode-1

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
#include <stdexcept>
using namespace std;

string  dn[] = {"SOUTH", "EAST", "NORTH", "WEST"};
int     dr[] = {1, 0, -1, 0};
int     dc[] = {0, 1, 0, -1};

int getDirIndex(char c)
{
	static map<char, int> dp;

	if (dp.find(c) != dp.end())
		return dp[c];

	for (int d = 0; d < 4; d++)
		if (c == dn[d][0])
			return dp[c] = d;
	return dp[c] = -1;
}

struct Grid
{
	int rows;
	int cols;

	vector<string> grid;

	void read( void )
	{
		cin >> this->rows >> this->cols; cin.ignore();
		grid.resize(this->rows);
		for (auto &r : grid)
		{
			getline(cin, r);
		}
	}

	pair<int, int> getPlayePos( void )
	{
		static pair<int, int> dp {-1, -1};

		if (dp.first != -1 && dp.second != -1)
			return (dp);

		for (int i = 0; i < this->rows; i++)
			for (int j = 0; j < this->cols; j++)
				if (this->grid[i][j] == '@')
				{
					this->grid[i][j] = ' ';
					return dp = {i, j};
				}

		return dp;
	}

	bool goodPos(int _r, int _c)
	{
		if (_r < 0 || _c < 0 || _r >= this->rows || _c >= this->cols)
			return false;

		if (this->grid[_r][_c] == '#')
			return false;

		return true;
	}


	void debug( void )
	{
		cerr << this->rows << " " << this->cols << endl;
		cerr << "/* start map log */\n";
		for (auto &r : grid)
			cerr << r << "\n";
		cerr << "/* /* end */ */\n\n";
		cerr.flush();
	}
};

struct Blunder
{
	int     r_pos;
	int     c_pos;
	int     cur_direction;
	int     coef_direction;
	bool    breaker_mode;

	Blunder(int _r_pos, int _c_pos) 
	: r_pos(_r_pos), c_pos(_c_pos), cur_direction(0), coef_direction(1), breaker_mode(false)
	{
	}

	Blunder(int _r_pos, int _c_pos, int dir, int coef, int _breaker_mode) 
	: r_pos(_r_pos), c_pos(_c_pos), cur_direction(dir), coef_direction(coef), breaker_mode(_breaker_mode)
	{
	}

	Blunder(const Blunder &other) 
	:   r_pos(other.r_pos), c_pos(other.c_pos), cur_direction(other.cur_direction), 
		coef_direction(other.coef_direction), breaker_mode(other.breaker_mode)
	{
	}

	Blunder &operator=(const Blunder &other)
	{
		this->r_pos = other.r_pos;
		this->c_pos = other.c_pos;
		this->cur_direction = other.cur_direction;
		this->coef_direction = other.coef_direction;
		this->breaker_mode = other.breaker_mode;
		return *this;
	}

	vector<int> constructKey( void )
	{
		return (vector<int>{this->r_pos, this->c_pos, this->cur_direction, this->coef_direction, this->breaker_mode});
	}
};

struct Actions
{
	vector<string> actions;

	void operator<<(string action)
	{
		this->actions.push_back(action);
	}
};

struct Teleporters
{
	vector< pair<int, int> >                telporters;
	map< pair<int, int>, pair<int, int> >   teleporterMapto;

	void operator<<(pair<int, int> _pos)
	{
		this->telporters.push_back(_pos);
	}

	void findTeleporters(const Grid &grid)
	{
		if (!this->telporters.empty())
			return ;

		for (int i = 0; i < grid.rows; i++)
			for (int j = 0; j < grid.cols; j++)
				if (grid.grid[i][j] == 'T')
				{
					this->telporters.push_back({i, j});
				}

		if (this->telporters.size() != 2)
			return ;

		teleporterMapto[this->telporters.front()] = this->telporters.back();
		teleporterMapto[this->telporters.back()] = this->telporters.front();
	}
};

ostream &operator<<(ostream &os, Actions &actions)
{
	for (size_t i = 0; i < actions.actions.size(); i++)
	{
		os << actions.actions[i];
		if (i+1 < actions.actions.size())
			cout << "\n";
	}
	return os;
}

ostream &operator<<(ostream &os, Blunder &b)
{
	os << "Blunder:: Postion(" << b.r_pos << ", " << b.c_pos << ")";
	os << " Direction: " << b.cur_direction << " Coef: " << b.coef_direction;
	os << " BreakerMode: " << (b.breaker_mode ? "TRUE" : "FALSE");
	os << "\n" << endl;
	return os;
}

int main()
{
	Grid    grid;  grid.read();
	// grid.debug();
	Blunder blunder(grid.getPlayePos().first, grid.getPlayePos().second);
	Teleporters teleporters; teleporters.findTeleporters(grid);


	Actions actions;

	queue< Blunder > road;     road.push(blunder);
	map< pair< vector<int>, vector<string> >, bool >    visited; /* Key Blunder-{row, col, dir, coefDir, breakerMode} */
	bool    loop = false;

	// start simulating the process...
	while (!road.empty())
	{

		Blunder curBlunder(road.front());   road.pop();

		// cerr << grid.grid[curBlunder.r_pos][curBlunder.c_pos] << ' ' << curBlunder << endl;

		char    &cur_char   = grid.grid[curBlunder.r_pos][curBlunder.c_pos];

		if (cur_char == '$')
		{
			break ;
		}

		if (visited.find( {curBlunder.constructKey(), grid.grid} ) != visited.end())
		{
			loop = true;
			break ; 
		}

		visited[{curBlunder.constructKey(), grid.grid}] = true;

		if (getDirIndex(cur_char) != -1)
		{
			curBlunder.cur_direction = getDirIndex(cur_char);
		}
		else if (cur_char == 'I')
		{
			curBlunder.coef_direction = ((curBlunder.coef_direction == 1) ? -1 : 1);
		}
		else if (cur_char == 'B')
		{
			curBlunder.breaker_mode = !(curBlunder.breaker_mode);
		}
		else if (cur_char == 'T')
		{
			pair<int, int> cur_pos{curBlunder.r_pos, curBlunder.c_pos};

			if (teleporters.teleporterMapto.find(cur_pos) != teleporters.teleporterMapto.end())
			{
				curBlunder.r_pos = teleporters.teleporterMapto[cur_pos].first;
				curBlunder.c_pos = teleporters.teleporterMapto[cur_pos].second;
			}
		}

		bool succesMoving = false;

		int new_r = curBlunder.r_pos + dr[curBlunder.cur_direction];
		int new_c = curBlunder.c_pos + dc[curBlunder.cur_direction];

		if (grid.goodPos(new_r, new_c))
		{
			if (grid.grid[new_r][new_c] != 'X') 
			{
				succesMoving = true;
				curBlunder.r_pos = new_r;
				curBlunder.c_pos = new_c;
			}
			else if ((grid.grid[new_r][new_c] == 'X') &&  curBlunder.breaker_mode)
			{
				grid.grid[new_r][new_c] = ' ';
				succesMoving = true;
				curBlunder.r_pos = new_r;
				curBlunder.c_pos = new_c;
			}
		}

		if (!succesMoving)
		{
			// change direction and try again
			if (curBlunder.coef_direction == 1)
				curBlunder.cur_direction = 0;
			else
				curBlunder.cur_direction = 3;

			for (int d = 0; d < 4; d++)
			{
				new_r = curBlunder.r_pos + dr[curBlunder.cur_direction];
				new_c = curBlunder.c_pos + dc[curBlunder.cur_direction];

				if (grid.goodPos(new_r, new_c))
				{
					if ((grid.grid[new_r][new_c] != 'X') 
						|| ((grid.grid[new_r][new_c] == 'X') && curBlunder.breaker_mode))
					{
						if (grid.grid[new_r][new_c] == 'X')
							grid.grid[new_r][new_c] = ' ';
						succesMoving = true;
						curBlunder.r_pos = new_r;
						curBlunder.c_pos = new_c;
						break ;
					}
				}

				curBlunder.cur_direction += curBlunder.coef_direction;
			}
		}

		if (succesMoving)
		{
			road.push(curBlunder);
			actions << dn[curBlunder.cur_direction];
		}
		else
		{
			loop = true;
			break ;
		}
	}

	if (!loop)
	{
		cout << actions << endl;
	}
	else
	{
		cout << "LOOP" << endl;
	}

	return (0);
}
