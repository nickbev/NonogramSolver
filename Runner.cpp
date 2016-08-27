#include "Nonogram.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using std::string;
using std::cout;
using std::ifstream;
using std::vector;
using std::getline;
using std::cerr;
using std::stoi;
using std::istringstream;
using std::istream_iterator;
using std::copy;

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cerr << "Invalid arguments: must have one text file";
		exit(1);
	}
	
	string filename = argv[1];
	cout << "Opening " + filename + ".\n";
	ifstream is;
	string junk;
	is.open(filename);

	if (!is.is_open())
	{
		cerr << "File " + filename + " could not be opened";
		exit(1);
	}

	int size = 0;
	vector<vector<int>> across, down;

	is >> size;
	getline(is, junk);
	getline(is, junk);

	for (int x = 0; x < size; ++x)
	{
		vector<int> add;
		across.push_back(add);

		string line;
		getline(is, line);
		// DIVIDE STRING INTO SUBSTRINGS SEPARATING BY SPACE
		vector<string> nums;
		istringstream iss(line);
		copy(istream_iterator<string>(iss),
			istream_iterator<string>(),
			back_inserter(nums));

		for (int y = 0; y < nums.size(); ++y)
		{
			across[x].push_back(stoi(nums[y]));
		}
	}

	getline(is, junk);
	int max = 0;

	for (int x = 0; x < size; ++x)
	{
		vector<int> add;
		down.push_back(add);

		string line;
		getline(is, line);
		// DIVIDE STRING INTO SUBSTRINGS SEPARATING BY SPACE
		vector<string> nums;
		istringstream iss(line);
		copy(istream_iterator<string>(iss),
			istream_iterator<string>(),
			back_inserter(nums));

		if (nums.size() > max)
		{
			max = nums.size();
		}

		for (int y = 0; y < nums.size(); ++y)
		{
			down[x].push_back(stoi(nums[y]));
		}
	}

	Nonogram solver(size, across, down, max);

	solver.solve();

	return 0;
}