/*
ID: seankeller2010
LANG: C++
TASK: butter
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <functional>

#define INF 1 << 25

using namespace std;

bool checked[501][801];
int dist[501][801];
int cows[501];
vector<pair<int, int> > adj[801];

int N, P, C;
int first, second, length;

int main()
{
	ifstream fin("butter.in");
	ofstream fout("butter.out");
	fin >> N >> P >> C;
	for (int i = 1; i <= N; i++) fin >> cows[i];
	for (int i = 0; i < C; i++) {
		fin >> first >> second >> length;
		adj[first].push_back(make_pair(length, second));
		adj[second].push_back(make_pair(length, first));
	}
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > tocheck;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= P; j++)
			if (j != cows[i]) dist[i][j] = INF;
		tocheck.push(make_pair(0, cows[i]));
		while (!tocheck.empty()) {
			pair <int, int> working = tocheck.top();
			tocheck.pop();
			if (checked[i][working.second]) continue;
			checked[i][working.second] = true;
			for (int j = 0; j < adj[working.second].size(); j++) {
				if (checked[i][adj[working.second][j].second]) continue;
				if (dist[i][adj[working.second][j].second] > working.first + adj[working.second][j].first) {
					dist[i][adj[working.second][j].second] = working.first + adj[working.second][j].first;
					tocheck.push(make_pair(dist[i][adj[working.second][j].second], adj[working.second][j].second));
				}
			}
		}
	}
	int min = INF;
	for (int i = 1; i <= P; i++) {
		int total = 0;
		for (int j = 1; j <= N; j++)
			total += dist[j][i];
		if (total < min) min = total;
	}
	fout << min << endl;
	//system("PAUSE");
    return 0;
}