/*
ID: seankeller2010
LANG: C++11
TASK: shortcut
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

using namespace std;

#define INF 1 << 30

int N, M, T, temp1;
int numcows[10001];
int cowsthrough[10001];
int z[10001];
vector< pair<int, int> > adj[10001];
bool vis[10001];

int first, second, length;

struct paths {
	int dist;
	int dest;
	vector<int> path;

	paths(int _dist, int _dest, vector<int> _path) {
		dist = _dist;
		dest = _dest;
		path = _path;
	}

	inline bool operator < (const paths& obj) const{	
		if (dist != obj.dist) return dist > obj.dist;
		return !(lexicographical_compare(path.rbegin(), path.rend(), obj.path.rbegin(), obj.path.rend()));
	}
};

int main()
{
	ifstream fin("shortcut.in");
	ofstream fout("shortcut.out");
	fin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		fin >> temp1;
		numcows[i] = temp1;
	}
	for (int i = 0; i < M; i++) {
		fin >> first >> second >> length;
		adj[first - 1].push_back(make_pair(length, second - 1));
		adj[second - 1].push_back(make_pair(length, first - 1));
	}

	priority_queue<paths> tocheck;
	for (int i = 0; i < adj[0].size(); i++) {
		vector<int> empty;
		tocheck.push(paths(adj[0][i].first, adj[0][i].second, empty));
	}
	vis[0] = true;
	while (!tocheck.empty()) {
		paths working = tocheck.top();
		tocheck.pop();
		if (vis[working.dest]) continue;
		vis[working.dest] = true;
		z[working.dest] = working.dist;
		working.path.push_back(working.dest);
		for (int i = 0; i < working.path.size(); i++) cowsthrough[working.path[i]] += numcows[working.dest];
		for (int i = 0; i < adj[working.dest].size(); i++) tocheck.push(paths(working.dist + adj[working.dest][i].first, adj[working.dest][i].second, working.path));
	}

	//for (int i = 0; i < N; i++) cout << z[i] << " " << cowsthrough[i] << endl;



	long long best = 0;
	for (int i = 1; i < N; i++) best = max(best, ((long long)cowsthrough[i] * (long long)(z[i] - T)));
	fout << best << endl;
	//system("PAUSE");
    return 0;
}

