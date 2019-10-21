/*
ID: seankeller2010
LANG: C++11
TASK: bphoto
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



#define MAXN (1 << 17)

int BT[MAXN];
int N;
vector<pair<int, int> > cows;

void bit_add(int x, int v) {
	for (int i = x | MAXN; i < (MAXN << 1); i += i & -i) {
		BT[i ^ MAXN] += v;
	}
}

int bit_get(int x) {
	int ret = 0;
	for (int i = x - 1; x != 0; i &= i - 1) {
		ret += BT[i];
		if (!i) break;
	}
	return ret;
}

int main()
{
	ifstream fin("bphoto.in");
	ofstream fout("bphoto.out");
	fin >> N;
	for (int i = 0; i < N; i++) {
		int height = 0;
		fin >> height;
		cows.push_back(make_pair(height, i));
	}
	sort(cows.begin(), cows.end());
	reverse(cows.begin(), cows.end());
	int count = 0;
	for (int i = 0; i < N; i++) {
		pair<int, int> working = cows[i];
		int lhs = bit_get(working.second);
		int rhs = i - lhs;
		if (max(lhs, rhs) > 2 * min(lhs, rhs))
			count++;
		bit_add(working.second, 1);
	}
	fout << count << endl;
	//system("PAUSE");
    return 0;
}

