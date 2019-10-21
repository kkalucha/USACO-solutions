/*
ID: georgewolles
LANG: C++11
TASK: hoofball
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

vector<int> pos;
int closest[100];
bool visited[100];
int comp[101];

int N;

vector<int> find(int index) {
	vector<int> result;
	for (int i = 0; i < N; i++)
		if (closest[i] == index)
			result.push_back(i);
	return result;
}

int main()
{
	ifstream fin("hoofball.in");
	ofstream fout("hoofball.out");
	fin >> N;
	for (int i = 0; i < N; i++) {
		int a = 0;
		fin >> a;
		pos.push_back(a);
	}
	sort(pos.begin(), pos.end());
	closest[0] = 1;
	closest[N - 1] = N - 2;
	for (int i = 1; i < N - 1; i++)
		closest[i] = pos[i] - pos[i - 1] > pos[i + 1] - pos[i] ? i + 1 : i - 1;
	int count = 0;
	for (;; count++) {
		queue<int> todo;
		int working = 0;
		for (; working < N && visited[working]; working++) {}
		if (working == N) break;
		int temp = working;
		todo.push(working);
		while (!todo.empty()) {
			int tooo = todo.front();
			todo.pop();
			//cout << "checking out pos: " << tooo << " for: " << working << endl;
			if (visited[tooo]) continue;
			visited[tooo] = true;
			vector<int> tovisit = find(tooo);
			for (int i = 0; i < tovisit.size(); i++) {
				todo.push(tovisit[i]);
			}
		}
		for (int i = 0; i < N; i++) {
			visited[temp] = true;
			temp = closest[temp];
		}
		//cout << count << endl;
	}
	fout << count << endl;
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < find(i).size(); j++)
			cout << find(i)[j] << " ";
		cout << endl;
	}*/
	//system("PAUSE");
    return 0;
}