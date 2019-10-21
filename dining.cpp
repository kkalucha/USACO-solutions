/*
ID: seankeller2010
LANG: C++11
TASK: dining
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <math.h>
#include <string>
#include <cstring>

using namespace std;

#define INF 1 << 30

int N, M, K;
int hay[50000];
int R[50000];
int E[50000];
int z[50000];
bool vis[50000];
vector< pair<int, int> > adj[50000];

int first, second, length;

int main()
{
	memset(hay, 0, sizeof(hay));
	fill_n(R, 50000, -1 * INF);
	memset(E, 0, sizeof(E));
	memset(z, 0, sizeof(z));
	memset(vis, false, sizeof(vis));
	ifstream fin("dining.in");
	ofstream fout("dining.out");
	fin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		fin >> first >> second >> length;
		adj[first - 1].push_back(make_pair(length, second - 1));
		adj[second - 1].push_back(make_pair(length, first - 1));
	}
	for (int i = 0; i < K; i++) {
		fin >> first >> length;
		hay[first - 1] = max(hay[first - 1], length);
	}

	priority_queue<pair<int, int> > tocheck;
	vector<pair<int, int> > hays;

	vis[N - 1] = true;
	for (int i = 0; i < adj[N - 1].size(); i++) {
		tocheck.push(make_pair(-1 * adj[N - 1][i].first, adj[N - 1][i].second));
	}
	while (!tocheck.empty()) {
		pair<int, int> working = tocheck.top();
		tocheck.pop();
		if (vis[working.second]) continue;
		int dist = -1 * working.first;
		int dest = working.second;
		vis[dest] = true;
		if (hay[dest] > 0) {
			hays.push_back(make_pair(dist, dest));
			R[dest] = hay[dest];
		}
		z[dest] = dist;
		for (int i = 0; i < adj[dest].size(); i++) tocheck.push(make_pair(-1 * dist + -1 * adj[dest][i].first, adj[dest][i].second));
	}

	for (int i = 0; i < N; i++) cout << z[i] << " " << R[i] << endl;

	for (int i = 0; i < hays.size(); i++) {
		if (hays[i].first * 2 <= hay[hays[i].second]) {
			for (int j = 0; j < N - 1; j++)
				fout << 1 << endl;
			//system("PAUSE");
			return 0;
		}
		E[hays[i].second] = hay[hays[i].second] - hays[i].first;
	}
	//cout << hays[0].first << " " << hays[0].second << " " << E[hays[0].second] << endl;
	priority_queue<pair<int, int> > tohay;
	for (int i = 0; i < hays.size(); i++) {
		for (int j = 0; j < adj[hays[i].second].size(); j++) {
			tohay.push(make_pair(E[hays[i].second] - adj[hays[i].second][j].first, adj[hays[i].second][j].second));
		}
	}
	while (!tohay.empty()) {
		pair<int, int> working = tohay.top();
		tohay.pop();
		int E_x = working.first;
		int dest = working.second;
		if (dest == N - 1) continue;
		if (E_x + z[dest] > R[dest]) {
			R[dest] = E_x + z[dest];
			for (int i = 0; i < adj[dest].size(); i++)
				tohay.push(make_pair(E_x - adj[dest][i].first, adj[dest][i].second));
		}
	}
	//for (int i = 0; i < N - 1; i++) cout << R[i] << endl;
	for (int i = 0; i < N - 1; i++) fout << (R[i] >= 0) << endl;
	//system("PAUSE");
    return 0;
}