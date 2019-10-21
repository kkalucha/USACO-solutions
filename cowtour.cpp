/*
ID: seankeller2010
LANG: C++
TASK: cowtour
*/

//#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int fields[150];
int pastures[150][2];
vector<int> adj[150];
bool visited[150];
double distances[150][150];
double dista[150][150];
double diam[150];
double fielddiams[151];
int N;

double dist(int a, int b) {
	if (distances[a][b] == 0) {
		double distancee = sqrt((pastures[a][0] - pastures[b][0]) * (pastures[a][0] - pastures[b][0]) + (pastures[a][1] - pastures[b][1]) * (pastures[a][1] - pastures[b][1]));
		distances[a][b] = distancee;
		distances[b][a] = distancee;
	}
	return distances[a][b];
}

int main()
{
	ifstream fin("cowtour.in");
	ofstream fout("cowtour.out");
	fin >> N;
	for (int i = 0; i < N; i++) fin >> pastures[i][0] >> pastures[i][1];
	string tem2 = "";
	getline(fin, tem2);
	for (int i = 0; i < N; i++) {
		string temp = "";
		getline(fin, temp);
		for (int j = 0; j < N; j++) {
			char tempc = 0;
			tempc = temp.at(j);
			if (tempc == '1') adj[i].push_back(j);
		}
	}
	//for (int i = 0; i < N; i++) cout << pastures[i][0] << " " << pastures[i][1] << endl;
	int count = 1;
	for (int i = 0; i < N;) {
		queue<int> tonum;
		int j = 0;
		for (; j < N; j++) if (fields[j] == 0) break;
		tonum.push(j);
		while (!tonum.empty()) {
			if (fields[tonum.front()] == 0) {
				fields[tonum.front()] = count;
				i++;
				for (int k = 0; k < adj[tonum.front()].size(); k++) tonum.push(adj[tonum.front()][k]);
			}
			tonum.pop();
		}
		count++;
	}
	//cout << maximum(0) << endl;
	//for (int i = 0; i < N; i++) if (fields[i] != 1) cout << i << " " << fields[i];
	double mindiam = 9999999;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) if (i != j) dista[i][j] = 1 << 25;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < adj[i].size(); j++) {
			dista[i][adj[i][j]] = dist(i, adj[i][j]);
			dista[adj[i][j]][i] = dista[i][adj[i][j]];
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++) {
				if (dista[j][i] + dista[i][k] < dista[j][k]) dista[j][k] = dista[j][i] + dista[i][k];
			}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (dista[i][j] != 1 << 25 && diam[i] < dista[i][j]) diam[i] = dista[i][j];
			if (diam[i] > fielddiams[fields[i]]) fielddiams[fields[i]] = diam[i];
		}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (fields[i] != fields[j] && max(max(diam[i] + diam[j] + dist(i, j), fielddiams[fields[i]]), fielddiams[fields[j]]) < mindiam) 
				mindiam = max(max(diam[i] + diam[j] + dist(i, j), fielddiams[fields[i]]), fielddiams[fields[j]]);
		}
	}
	fout << fixed << setprecision(6) << mindiam << endl;
	//system("PAUSE");
    return 0;
}