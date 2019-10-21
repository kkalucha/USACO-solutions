/*
ID: seankeller2010
LANG: C++11
TASK: moocast
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

map<int, int> depth[100000];
vector<int> children[100000];
bool isFile[100000];
int parent[100000];
int length[100000];
int N, m;
string name;

int explore(int n) {
	if (depth[n].size() != 0)
		return depth[n].size();
	int num = 0;
	for (int i = 0; i < depth[n].size(); i++)
		num += explore(depth[n][4]);
}
int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> name >> m;
		length[i] = name.length() + 1;
		if (m == 0) {
			length[i]--;
			isFile[i] = true;
		}
		for (int j = 0; j < m; j++) {
			int temp = 0;
			cin >> temp;
			children[i].push_back(temp - 1);
		}
	}
	explore(0);
    return 0;
}

