/*
ID: seankeller2010
LANG: C++11
TASK: taming
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

int dp[101][101];
int real[100];
int N, temp;

int main()
{
	ifstream fin("taming.in");
	ofstream fout("taming.out");
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> temp;
		real[i] = temp;
	}
	for (int i = 0; i < 101; i++)
		for (int j = 0; j < 101; j++)
			dp[i][j] = INF;
	for (int i = 1; i <= N; i++) {
		int diff = 0;
		for (int j = 0; j < i; j++) if (real[j + N - i] != j) diff++;
		dp[i][1] = diff;
		//cout << dp[i][1] << endl;
	}

	for (int out = 2; out <= N; out++) {
		for (int i = out; i <= N; i++) {
			if (i == out) {
				int diff = 0;
				for (int k = 0; k < i; k++)
					if (real[N - i + k] != 0) diff++;
				dp[i][out] = diff;
				continue;
			}
			for (int j = 1; j < i; j++) {
				int diff = 0;
				for (int k = 0; k < j; k++) {
					if (real[N - i + k] != k) diff++;
				}
				//if (diff + dp[i - j][out - 1] < dp[i][out]) cout << "dp " << i << " " << out << " " << diff + dp[i - j][out - 1] << endl;
				if (out - 1 <= i - j) dp[i][out] = min(dp[i][out], diff + dp[i - j][out - 1]);
			}
		}
	}
	//cout << dp[3][3] << endl;
	for (int i = 1; i <= N; i++) {
		fout << dp[N][i] << endl;
	}
	//system("PAUSE");
    return 0;
}

