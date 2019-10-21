/*
ID: seankeller2010
LANG: C++11
TASK: piepie
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

#define INF 1 << 25;

using namespace std;

vector<int> adjb[100000];
vector<int> adje[100000];
int best[200000];

int N, D, temp1, temp2;

vector<pair<int, int> >bes;
vector<pair<int, int> >els;

int main()
{
	ifstream fin("piepie.in");
	ofstream fout("piepie.out");
	fin >> N >> D;
	for (int i = 0; i < 2 * N; i++) {
		fin >> temp1 >> temp2;
		bes.push_back(make_pair(temp1, i));
		els.push_back(make_pair(temp2, i));
	}
	sort(bes.begin(), bes.end());
	sort(els.begin(), els.end());
	//for (int i = 0; i < 2 * N; i++) cout << "i: " << i << " first: " << bes[i].first << " second: " << bes[i].second << endl;
	//for (int i = 0; i < 2 * N; i++) cout << "i: " << i << " first: " << els[i].first << " second: " << els[i].second << endl;
	for (int i = 0; i < 2 * N; i++) {
		for (int j = i + 1; j < 2 * N && bes[j].first - bes[i].first <= D; j++) {
			if (bes[j].second >= N && bes[i].second < N) {
				adjb[bes[i].second].push_back(bes[j].second);
			}
			else if (bes[j].second < N && bes[i].second >= N) {
				adjb[bes[j].second].push_back(bes[i].second);
			}
		}
	}
	for (int i = 0; i < 2 * N; i++) {
		for (int j = i + 1; j < 2 * N && els[j].first - els[i].first <= D; j++) {
			if (els[j].second >= N && els[i].second < N) {
				adjb[els[j].second].push_back(els[i].second);
			}
			else if (els[j].second < N && els[i].second >= N) {
				adjb[els[i].second].push_back(els[j].second);
			}
		}
	}
	for (int i = 0; i < 2 * N; i++)
		for (int j = 0; j < adjb[i].size(); j++) {
			//cout << "adj to " << i << " is " << j << endl;
		}
	for (int i = 0; i < 2 * N; i++) best[i] = INF;
	queue<int> tocheckbes;
	for (int i = 0; bes[i].first == 0; i++) {
		best[bes[i].second] = 1;
		tocheckbes.push(bes[i].second);
	}
	for (int i = 0; els[i].first == 0; i++) {
		best[els[i].second] = 1;
		tocheckbes.push(els[i].second);
	}
	while(!tocheckbes.empty()) {
		int working = tocheckbes.front();
		for (int j = 0; j < adjb[working].size(); j++) {
			best[adjb[working][j]] = min(best[working] + 1, best[adjb[working][j]]);
			tocheckbes.push(adjb[working][j]);
		}
		tocheckbes.pop();
	}
	for (int i = 0; i < N; i++)
		fout << best[i] << endl;
	//system("PAUSE");
    return 0;
}