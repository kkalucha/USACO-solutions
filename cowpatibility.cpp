/*
ID: seankeller2010
LANG: C++11
TASK: cowpatibility
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define INF 1 << 30

int N, counter;
unordered_map<int, unordered_set<int> > hashes;

int main()
{
	ifstream fin("cowpatibility.in");
	ofstream fout("cowpatibility.out");
	fin >> N;
	counter = 0;
	for (int i = 0; i < N; i++) {
		unordered_set<int> thisguy;
		for (int j = 0; j < 5; j++) {
			int temp = 0;
			fin >> temp;
			auto finder = hashes.find(temp);
			if (finder == hashes.end()) {
				unordered_set<int> empty;
				empty.insert(i);
				hashes.insert({ temp, empty });
			}
			else {
				thisguy.insert(finder->second.begin(), finder->second.end());
				finder->second.insert(i);
			}
		}
		counter += thisguy.size();
		}
	fout << (N * (N - 1)) / 2 - counter << endl;
	//system("PAUSE");
    return 0;
}