/*
ID: seankeller2010
LANG: C++
TASK: inflate
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int M, N, timee, score;
int dp[10001];
int vals[10001][2];

int main()
{
	ifstream fin("inflate.in");
	ofstream fout("inflate.out");
	fin >> M >> N;
	for (int i = 0; i < N; i++) {
		fin >> score >> timee;
		vals[i][0] = score;
		vals[i][1] = timee;
	}
	dp[0] = 0;
	for (int i = 1; i <= M; i++)
		for (int j = 0; j < N; j++)
			if (i - vals[j][1] >= 0 && dp[i - vals[j][1]] + vals[j][0] > dp[i]) dp[i] = dp[i - vals[j][1]] + vals[j][0];
	fout << dp[M] << endl;
	//system("PAUSE");
    return 0;
}