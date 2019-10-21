/*
ID: seankeller2010
LANG: C++11
TASK: spainting
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

long long N, M, K;
long long dp[1000001];
long long powers[1000001];

int main()
{
	ifstream fin("spainting.in");
	ofstream fout("spainting.out");
	fin >> N >> M >> K;
	dp[N] = M;
	powers[0] = 1;
	for (int i = 1; i <= N; i++)
		powers[i] = (powers[i - 1] * M) % 1000000007;
	for (int i = N - 1; i >= K; i--)
		dp[i] = (M * (dp[i - 1] + powers[i - K] - powers[i - K - 1] - dp[i - K] + dp[i - K - 1])) % 1000000007;
	fout << dp[K] << endl;
	//system("PAUSE");
    return 0;
}