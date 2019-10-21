/*
ID: seankeller2010
LANG: C++11
TASK: teamwork
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

int N, K;
int cows[10005];
int dp[11005];

int main()
{
	ifstream fin("teamwork.in");
	ofstream fout("teamwork.out");
	fin >> N >> K;
	for (int i = 0; i < N; i++)
		fin >> cows[i];
	fill_n(dp, 11005, 0);
	int maxin = 0;
	for (int i = 0; i < K; i++) {
		maxin = max(maxin, cows[i]);
		dp[i] = maxin * (i + 1);
	}
	for (int i = 0; i < N; i++) {
		int maxi = 0;
		for (int j = 1; j <= K; j++) {
			maxi = max(maxi, cows[i + j]);
			dp[i + j] = max(dp[i + j], dp[i] + maxi * j);
		}
	}
	//for (int i = 0; i < N; i++) cout << dp[i] << endl;
	fout << dp[N - 1] << endl;
	//system("PAUSE");
    return 0;
}

