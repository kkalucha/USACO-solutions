// planting.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adj[100001];
bool isTaken[100001];
int color[100001];
int N, temp1, temp2;


int main()
{
	ifstream fin("planting.in");
	ofstream fout("planting.out");
	fin >> N; 
	for (int i = 0; i < N - 1; i++) {
		fin >> temp1 >> temp2;
		adj[temp1 - 1].push_back(temp2 - 1);
		adj[temp2 - 1].push_back(temp1 - 1);
	}
	queue<int> todo;
	color[0] = 1;
	for (int i = 0; i < adj[0].size(); i++) todo.push(adj[0][i]);

	while (!todo.empty()) {
		int working = todo.front();
		todo.pop();
		if (color[working]) continue;
		fill_n(isTaken, 100001, 0);
		for (int i = 0; i < adj[working].size(); i++) {
			isTaken[color[adj[working][i]]] = true;
			for (int j = 0; j < adj[adj[working][i]].size(); j++) {
				isTaken[color[adj[adj[working][i]][j]]] = true;
			}
			todo.push(adj[working][i]);
		}
		for (int i = 1; i < 100001; i++) if (!isTaken[i]) {
			color[working] = i;
			break;
		}
	}
	int best = 0;
	for (int i = 0; i < N; i++) best = max(best, color[i]);
	//for (int i = 0; i < N; i++) cout << color[i] << endl;
	fout << best << endl;
	//system("PAUSE");
    return 0;
}

