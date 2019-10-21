/*
ID: georgewolles
LANG: C++11
TASK: reststops
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cmath>
#include <math.h>
#include <string>

using namespace std;

#define INF 1 << 30

int L, N, F, B, t1, t2;
priority_queue<pair<int, int> > stops;

int main()
{
	ifstream fin("reststops.in");
	ofstream fout("reststops.out");
	fin >> L >> N >> F >> B;
	for (int i = 0; i < N; i++) {
		fin >> t1 >> t2;
		stops.push(make_pair(t2, t1));
	}
	int cur = 0;
	long total = 0;
	while (!stops.empty()) {
		pair<int, int> best = stops.top();
		stops.pop();
		if (best.second <= cur)
			continue;
		total += (F - B) * (F - B) * (best.second - cur) * best.first;
		//cout << "ate: " << (best.second - cur) * best.first * (F - B) << " at: " << best.second << endl;
		cur = best.second;
	}
	fout << total << endl;
	//system("PAUSE");
    return 0;
}