/*
ID: seankeller2010
LANG: C++11
TASK: moocast
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
#include <string>

using namespace std;


int N, countin;
int xy[1000][2];
int key[1000];
vector<pair<int, pair<int, int> > > edges;

int find(int x) {
	if (x == key[x]) return x;
	key[x] = find(key[x]);
	return key[x];
}

void merge(int x, int y) {
	key[find(x)] = find(y);
}
int main()
{
	ifstream fin("moocast.in");
	ofstream fout("moocast.out");
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> xy[i][0] >> xy[i][1];
		key[i] = i;
	}
	countin++;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int dist = (xy[i][0] - xy[j][0]) * (xy[i][0] - xy[j][0]) + (xy[i][1] - xy[j][1]) * (xy[i][1] - xy[j][1]);
			edges.push_back(make_pair(dist, make_pair(i, j)));
		}
	}
	sort(edges.begin(), edges.end());
	int lastedge = 0;
	for (int i = 0; countin < N; i++) {
		pair <int, pair<int, int> > working = edges[i];
		if (find(working.second.first) != find(working.second.second)) {
			merge(working.second.first, working.second.second);
			countin++;
			lastedge = working.first;
		}
	}
	fout << lastedge << endl;
	//system("PAUSE");
    return 0;
}

