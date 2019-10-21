/*
ID: seankeller2010
LANG: C++11
TASK: dirtraverse
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

int numC[10000];
vector<int> children[10000];
long leafcount[10000];
long names[10000];
long N, numD, numF, m;
string name;

long leafcounter(long index) {
	if (leafcount[index] >= 0) return leafcount[index];
	int count = 0;
	if (children[index].size() == 0) return 1;
	for (long i = 0; i < children[index].size(); i++)
		count += leafcounter(children[index][i]);
	leafcount[index] = count;
	return count;
}

int main()
{
	ifstream fin("dirtraverse.in");
	ofstream fout("dirtraverse.out");
	for (int i = 0; i < 10000; i++)
		leafcount[i] = -1;
	fin >> N;
	numF = 0;
	for (int i = 0; i < N; i++) {
		fin >> name >> m;
		names[i] = name.length() + 1;
		if (m == 0) {
			names[i]--;
			numF++;
		}
		for (int j = 0; j < m; j++) {
			int temp = 0;
			fin >> temp;
			children[i].push_back(temp - 1);
		}
	}
	numD = N - numF;
	queue<pair<int, int> > todo;
	long long total = 0;
	for (int i = 0; i < children[0].size(); i++)
		todo.push(make_pair(children[0][i], 0));
	while (!todo.empty()) {
		pair<int, int> visit = todo.front();
		todo.pop();
		if (children[visit.first].size() == 0) total += names[visit.first] + visit.second;
		for (int i = 0; i < children[visit.first].size(); i++) {
			todo.push(make_pair(children[visit.first][i], visit.second + names[visit.first]));
		}
	}
	todo.push(make_pair(total, 0));
	long minim = total;
	while (!todo.empty()) {
		pair<int, int> visit = todo.front();
		todo.pop();
		for (int i = 0; i < children[visit.second].size(); i++) {
			if (children[children[visit.second][i]].size() != 0 && ((leafcounter(visit.second) - leafcounter(children[visit.second][i])) * names[children[visit.second][i]] > 3 * (numF - leafcounter(children[visit.second][i])))) {
				minim = min(minim, visit.first - (((leafcounter(visit.second) - leafcounter(children[visit.second][i])) * names[children[visit.second][i]]) - 3 * (numF - leafcounter(children[visit.second][i]))));
				todo.push(make_pair(visit.first - (((leafcounter(visit.second) - leafcounter(children[visit.second][i])) * names[children[visit.second][i]]) - 3 * (numF - leafcounter(children[visit.second][i]))), children[visit.second][i]));
			}
		}
	}
	//for (int i = 0; i < N; i++)
		//cout << leafcounter(i) << endl;
	fout << minim + 5 << endl;
	//system("PAUSE");
    return 0;
}