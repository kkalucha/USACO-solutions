/*
ID: seankeller2010
LANG: C++11
TASK: poetry
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

int N, M, K, temp1, temp2;
char temp3;
long long lines[26] = { 0 };
long long lessthanwords[5001] = { 0 };
long long rhymes[5001] = { 0 };
vector<pair<int, int> > words;

long long powerr(long long x, long long n) {
	if (x == 0) return 0;
	long long result = 1;
	while (n > 0) {
		if (n % 2 == 1) {
			result = (result * x) % 1000000007;
		}
		x = (x * x) % 1000000007;
		n /= 2;
	}
	return result;
}

int main()
{
	ifstream fin("poetry.in");
	ofstream fout("poetry.out");
	fin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		fin >> temp1 >> temp2;
		if (temp1 > K) continue;
		if (temp1 == K) {
			rhymes[temp2]++;
			continue;
		}
		words.push_back(make_pair(temp1, temp2));
	}

	for (int i = 0; i < M; i++) {
		fin >> temp3;
		lines[temp3 - 'A']++;
	}
	lessthanwords[0] = 1;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < words.size(); j++) {
			if (i + words[j].first > K) continue;
			if (i + words[j].first == K) {
				rhymes[words[j].second] = (rhymes[words[j].second] + lessthanwords[i]) % 1000000007;
				continue;
			}
			lessthanwords[i + words[j].first] = (lessthanwords[i + words[j].first] + lessthanwords[i]) % 1000000007;
		}
	}

	//for (int i = 0; i < K; i++) cout << lessthanwords[i] << endl;
	//cout << rhymes[1] << endl;
	//cout << rhymes[2] << endl;
	bool empty = true;
	for (int i = 1; i <= N; i++) if (rhymes[i] != 0) empty = false;
	if (empty) {
		fout << 0 << endl;
		return 0;
	}

	long long result = 1;

	for (int i = 0; i < 26; i++) {
		if (lines[i] == 0) continue;
		long long temp4 = 0;
		for (int j = 1; j <= N; j++) {
			temp4 = (temp4 + powerr(rhymes[j], lines[i])) % 1000000007;
		}
		result = (result * temp4) % 1000000007;
	}
	fout << result << endl;
	//cin >> N >> K;
	//cout << powerr(N, K) << endl;
	//system("PAUSE");
    return 0;
}