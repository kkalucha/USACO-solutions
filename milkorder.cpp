/*
ID: seankeller2010
LANG: C++11
TASK: sort
*/

#include "stdafx.h"
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
int N, M, temp;
vector<int> rules[50001];
vector<int> adj[100000];
bool visited[100000];
bool rec[100000];

void tsort(int v, stack<int> &nodes) {
	visited[v] = true;
	for (int i = 0; i < adj[v].size(); i++)
		if (!visited[adj[v][i]])
			tsort(adj[v][i], nodes);
	nodes.push(v);
}

bool cyclic(int v) {
	if (visited[v] == false) {
		visited[v] = true;
		rec[v] = true;
		for (int i = 0; i < adj[v].size(); i++) {
			if (!visited[adj[v][i]] && cyclic(adj[v][i]))
				return true;
			else if (rec[adj[v][i]] == true)
				return true;
		}
	}
	rec[v] = false;
	return false;
}

bool works(int X) {
	adj->clear();
	memset(visited, false, N * sizeof(bool));
	memset(rec, false, N * sizeof(bool));
	int elig[100000];
	memset(elig, -1, N * sizeof(int));
	for (int i = 0; i < X; i++)
		for (int j = 0; j < rules[i].size() - 1; j++)
			adj[rules[i][j]].push_back(rules[i][j + 1]);
	for (int i = 0; i < N; i++) {
		if (adj[i].size() > 0 && elig[i] == -1)
			elig[i] = 1;
		for (int j = 0; j < adj[i].size(); j++) {
			elig[adj[i][j]] = 0;
		}
	}
	for (int i = 0; i < N; i++)
		//cout << cyclic(i) << endl;
		if(cyclic(i)) return false;
	memset(visited, false, N * sizeof(bool));
	stack<int> nodes;
	for (int i = N - 1; i >= 0; i--)
		if (elig[i] == 1 && visited[i] == false)
			tsort(i, nodes);
	while (!nodes.empty()){
		cout << nodes.top() + 1 << endl;
		nodes.pop();
	}
	return true;
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		for (int j = 0; j < temp; j++){
			int tem = 0;
			cin >> tem;
			rules[i].push_back(tem - 1);
		}
	}
	cout << works(3) << endl;
	system("PAUSE");
    return 0;
}