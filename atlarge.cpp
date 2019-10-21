/*
ID: seankeller2010
LANG: C++11
TASK: atlarge
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

int N, K, a, b;
int dp[100001];
bool vis[100001];
bool visi[100001];
vector<int> adj[100001];

/*int discover(int index) {
	if (dp[index] != -1) return dp[index];
	vis[index] = true;
	int mini = INF;
	if (adj[index].size() == 1) mini = 0;
	for (int i = 0; i < adj[index].size(); i++) {
		if (vis[adj[index][i]] == false)
			mini = min(discover(adj[index][i]) + 1, mini);
	}
	dp[index] = mini;
	return mini;
}*/

int relax(int index, int steps) {
	if (steps >= dp[index]) return 0;
	dp[index] = steps;
	for (int i = 0; i < adj[index].size(); i++) {
		relax(adj[index][i], steps + 1);
	}
	return 0;
}

int main()
{
	ifstream fin("atlarge.in");
	ofstream fout("atlarge.out");
	fin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		fin >> a >> b;
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	fill_n(dp, 100001, INF);
	//discover(0);
	for (int i = 0; i < N; i++) {
		if (adj[i].size() == 1) relax(i, 0);
	}
	//for (int i = 0; i < N; i++)
		//cout << dp[i] << endl;
	queue<pair<int, int> > tocheck;
	int farmers = 0;
	tocheck.push(make_pair(K - 1, 0));
	while (!tocheck.empty()) {
		pair<int, int> working = tocheck.front();
		tocheck.pop();
		visi[working.first] = true;
		if (dp[working.first] <= working.second)
		{
			//cout << working.first << " <- barn caught  steps -> " << working.second << endl;
			farmers++;
		}
		else
			for (int i = 0; i < adj[working.first].size(); i++)
				if (visi[adj[working.first][i]] == false) tocheck.push(make_pair(adj[working.first][i], working.second + 1));
	}
	fout << farmers << endl;
	//system("PAUSE");
    return 0;
}