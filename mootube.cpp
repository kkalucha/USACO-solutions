/*
ID: seankeller2010
LANG: C++11
TASK: mootube
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

int N, Q, a, b, c, d, e;
vector<pair<int, int> > adj[100000];

int main()
{
	ifstream fin("mootube.in");
	ofstream fout("mootube.out");
	fin >> N >> Q;
	for (int i = 0; i < N - 1; i++) {
		fin >> a >> b >> c;
		adj[a - 1].push_back(make_pair(c, b - 1));
		adj[b - 1].push_back(make_pair(c, a - 1));
	}
	for (int i = 0; i < Q; i++) {
		fin >> d >> e;
		int visited[100000] = { 0 };
		queue<int> tocheck;
		int count = 0;
		tocheck.push(e - 1);
		while (!tocheck.empty()) {
			int working = tocheck.front();
			tocheck.pop();
			visited[working] = true;
			count++;
			for (int i = 0; i < adj[working].size(); i++) {
				if (adj[working][i].first >= d && visited[adj[working][i].second] == false) tocheck.push(adj[working][i].second);
			}
		}
		fout << count - 1 << endl;
	}
	//system("PAUSE");
    return 0;
}

