/*
ID: seankeller2010
LANG: C++11
TASK: hayfeast
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

#define INF 1 << 30

using namespace std;

long N, M, first, second;
long flavor[100000];
long spice[100000];

long sumf[100000];
long mins[100000][18];
long minspice = INF;

long minq(int a, int b) {
	if (a == b) return spice[a];
	int j = (int)log2(b - a + 1);
	return max(spice[mins[a][j]], spice[mins[b - (1 << j) + 1][j]]);
}

long sumq(int a, int b) {
	if (a == b) return flavor[a];
	if (b == 0) return sumf[0];
	if (a == 0) return sumf[b];
	return sumf[b] - sumf[a - 1];
}

int main()
{
	ifstream fin("hayfeast.in");
	ofstream fout("hayfeast.out");
	fin >> N >> M;
	for (int i = 0; i < N; i++)
		fin >> flavor[i] >> spice[i];
	sumf[0] = flavor[0];
	for (int i = 1; i < N; i++)
		sumf[i] = flavor[i] + sumf[i - 1];
	for (int i = 0; i < N; i++)
		mins[i][0] = i;
	for (int j = 1; (1 << j) <= N; j++)
		for (int i = 0; (i + (1 << j) - 1) < N; i++) {
			mins[i][j] = spice[mins[i][j - 1]] > spice[mins[i + (1 << (j - 1))][j - 1]] ? mins[i][j - 1] : mins[i + (1 << (j - 1))][j - 1];
		}
	first = 0;
	second = 0;
	while (second < N - 1 || (second == N - 1 && first < N)) {
		//cout << "trying " << first << " " << second << endl;
		if (sumq(first, second) >= M) {
			minspice = min(minspice, minq(first, second));
			first++;
		}
		else second++;
	}
	//cout << query(2, 4) << endl;
	fout << minspice << endl;
	//system("PAUSE");
    return 0;
}