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
#include <math.h>
#include <string>

using namespace std;

int notallowed[100000];
int color[100000];
bool visited[100000];

int N, K;
int b1, b2;
vector<int> adj[100000];

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> b1 >> b2;
		adj[b1 - 1].push_back(b2 - 1);
		adj[b2 - 1].push_back(b1 - 1);
	}
	int count = 1;
	stack<pair<int, pair<int, int> > > tocheck;
	for (int i = 0; i < K; i++) {
		cin >> b1 >> b2;
		color[b1 - 1] = b2;
		for (int j = 0; j < adj[b1 - 1].size(); j++) {
			if (notallowed[adj[b1 - 1][j]]) {
				if (notallowed[adj[b1 - 1][j]] == b2) count *= 2;
				color[adj[b1 - 1][j]] = 5;
			}
			else {
				notallowed[adj[b1 - 1][j]] = b2;
				visited[b1 - 1] = true;
				tocheck.push(make_pair(b2, make_pair(2, adj[b1 - 1][j])));
			}
		}
	}
	
	while (!tocheck.empty()) {
		pair<int, pair<int, int> > working = tocheck.top();
		tocheck.pop();
		bool end = true;
		if (color[working.second.second]){}
		for (int i = 0; i < adj[working.second.second].size(); i++) {
			if (!visited[adj[working.second.second][i]]) {
				end = false;
				tocheck.push(make_pair(working.first, make_pair(2 * working.second.first, adj[working.second.second][i])));
			}
		}
		if (end) {

		}
		else count *= 2;
	}

    return 0;
}

