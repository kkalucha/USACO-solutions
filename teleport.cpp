/*
ID: seankeller2010
LANG: C++11
TASK: teleport
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <math.h>
#include <string>

using namespace std;

#define INF 1 << 30

int N, t1, t2, miny, maxy;
multimap<int, int> todo;

int main()
{
	ifstream fin("teleport.in");
	ofstream fout("teleport.out");
	fin >> N;
	miny = INF;
	maxy = -INF;
	long long total = 0;
	for (int i = 0; i < N; i++) {
		fin >> t1 >> t2;
		miny = min(miny, min(t1, t2));
		maxy = max(maxy, max(t1, t2));
		if (abs(t2) < abs(t1)) {
			int temp = t1;
			t1 = t2;
			t2 = temp;
		}
		total += abs(t2 - t1);
		if (((t1 >= 0 && t2 >= 0) || (t1 <= 0 && t2 <= 0)) && abs(t1) >= abs(t2) / 2) {
			continue;
		}
		if (t1 >= 0 && t2 >= 0) {
			todo.insert(pair<int, int> (2 * t1, -1));
			todo.insert(pair<int, int>(t2, 2));
			todo.insert(pair<int, int>(2 * t2 - 2 * t1, -1));
		}
		else {
			if (t1 <= 0 && t2 <= 0) {
				todo.insert(pair<int, int>(2 * t1, -1));
				todo.insert(pair<int, int>(t2, 2));
				todo.insert(pair<int, int>(2 * t2 - 2 * t1, -1));
			}
			else {
				if (t1 < t2) {
					todo.insert(pair<int, int>(2 * t1, -1));
					todo.insert(pair<int, int>(t1, 2));
					todo.insert(pair<int, int>(0, -2));
					todo.insert(pair<int, int>(t2, 2));
					todo.insert(pair<int, int>(2 * t2, -1));
				}
				else {
					todo.insert(pair<int, int>(2 * t2, -1));
					todo.insert(pair<int, int>(t2, 2));
					todo.insert(pair<int, int>(0, -2));
					todo.insert(pair<int, int>(t1, 2));
					todo.insert(pair<int, int>(2 * t1, -1));
				}
			}
		}
	}
	//cout << total << endl;
	map<int, int>::iterator it = todo.begin();
	int slope = it->second;
	int last = it->first;
	long long best = total;
	it++;
	for (; it != todo.end(); it++) {
		total += slope * (it->first - last);
		best = min(best, total);
		slope += it->second;
		last = it->first;
	}
	fout << best << endl;
	//system("PAUSE");
    return 0;
}

