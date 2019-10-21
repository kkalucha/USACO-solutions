/*
ID: seankeller2010
LANG: C++
TASK: maze1
*/

//#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>
#include <fstream>

using namespace std;

int map[201][201];
int graph[101][101];
int W, H;
queue<pair<int, int> > tocheck;

int main()
{
	ifstream fin("maze1.in");
	ofstream fout("maze1.out");
	fin >> W >> H;
	string tem2 = "";
	getline(fin, tem2);
	for (int i = 0; i < 101; i++) for (int j = 0; j < 101; j++) graph[i][j] = 99999;
	for (int i = 0; i < (2 * H + 1); i++) {
		string tem1 = "";
		getline(fin, tem1);
		//cout << tem1 << endl;
		for (int j = 0; j < tem1.length(); j++) {
			char temp = tem1.at(j);
			if (temp == '-' || temp == '|' || temp == '+') map[i][j] = 1;
			else {
				if (i == 0) {
					graph[0][(j - 1) / 2] = 1;
					tocheck.push(pair<int, int>(0, (j - 1) / 2));
				}
				if (i == 2 * H) {
					graph[H - 1][(j - 1) / 2] = 1;
					tocheck.push(pair<int, int>(H - 1, (j - 1) / 2));
				}
				if (j == 0) {
					graph[(i - 1) / 2][0] = 1;
					tocheck.push(pair<int, int>((i - 1) / 2, 0));
				}
				if (j == 2 * W) {
					graph[(i - 1) / 2][W - 1] = 1;
					tocheck.push(pair<int, int>((i - 1) / 2, W - 1));
				}
			}
		}
	}
	/*for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cout << graph[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < 2 * H + 1; i++) {
		for (int j = 0; j < 2 * W + 1; j++) cout << map[i][j] << " ";
		cout << endl;
	}*/
	while (!tocheck.empty()) {
		pair<int, int> working = tocheck.front();
		if (working.first != 0 && map[working.first * 2][working.second * 2 + 1] != 1 && (graph[working.first - 1][working.second] > graph[working.first][working.second] + 1 || graph[working.first - 1][working.second] == 0)) {
			graph[working.first - 1][working.second] = graph[working.first][working.second] + 1;
			tocheck.push(pair<int, int>(working.first - 1, working.second));
		}
		if (working.second != 0 && map[working.first * 2 + 1][working.second * 2] != 1 && (graph[working.first][working.second - 1] > graph[working.first][working.second] + 1 || graph[working.first][working.second - 1] == 0)) {
			graph[working.first][working.second - 1] = graph[working.first][working.second] + 1;
			tocheck.push(pair<int, int>(working.first, working.second - 1));
		}
		if (working.first < H - 1 && map[working.first * 2 + 2][working.second * 2 + 1] != 1 && (graph[working.first + 1][working.second] > graph[working.first][working.second] + 1 || graph[working.first + 1][working.second] == 0)) {
			graph[working.first + 1][working.second] = graph[working.first][working.second] + 1;
			tocheck.push(pair<int, int>(working.first + 1, working.second));
		}
		if (working.second < W - 1 && map[working.first * 2 + 1][working.second * 2 + 2] != 1 && (graph[working.first][working.second + 1] > graph[working.first][working.second] + 1 || graph[working.first][working.second + 1] == 0)) {
			graph[working.first][working.second + 1] = graph[working.first][working.second] + 1;
			tocheck.push(pair<int, int>(working.first, working.second + 1));
		}
		tocheck.pop();
	} //--rupi kaur
	/*for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cout << graph[i][j] << " ";
		cout << endl;
	}*/
	int max = 0;
	for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) if (graph[i][j] > max) max = graph[i][j];
	fout << max << endl;
	//system("PAUSE");
    return 0;
}