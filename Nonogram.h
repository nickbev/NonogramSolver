#pragma once
#include <vector>
#include <iostream>

using std::vector;
using std::cout;

class Nonogram
{
private:
	
	enum State {UNKNOWN, BLACK, WHITE};
	vector<vector<State>> graph;
	vector<vector<int>> across;
	vector<vector<int>> down;
	const int defaultSize = 10;
	int size;
	int max;

public:

	Nonogram()
	{
		for (int x = 0; x < defaultSize; ++x)
		{
			vector<State> add;
			graph.push_back(add);
			
			for (int y = 0; y < defaultSize; ++y)
			{
				graph[x].push_back(UNKNOWN);
			}
		}
		size = defaultSize;
		max = 1;
	}

	Nonogram(int s, vector<vector<int>> a, vector<vector<int>> d, int m) 
	{
		for (int x = 0; x < s; ++x)
		{
			vector<State> add;
			graph.push_back(add);
			
			for (int y = 0; y < s; ++y)
			{
				graph[x].push_back(UNKNOWN);
			}
		}
		size = s;
		across = a;
		down = d;
		max = m;
	};

	void print()
	{
		for (int y = max; y > 0; --y)
		{
			cout << "          ";
			for (int x = 0; x < size; ++x)
			{
				int index = down[x].size() - y;
				if (index >= 0)
				{
					cout << down[x][index] << " ";
				}
				else
				{
					cout << "  ";
				}
			}
			cout << '\n';
		}
		
		for (int x = 0; x < size; ++x)
		{
			for (int a = across[x].size(); a < 5; ++a)
			{
				cout << "  ";
			}
			for (int a = 0; a < across[x].size(); ++a)
			{
				cout << across[x][a] << " ";
			}

			for (int y = 0; y < size; ++y)
			{
				switch (graph[x][y])
				{
					case UNKNOWN:
						cout << "? ";
						break;
					case BLACK:
						cout << "X ";
						break;
					case WHITE:
						cout << "- ";
						break;
				}
			}
			cout << '\n';
		}
	}

	void solve()
	{
		print();
	}

};

