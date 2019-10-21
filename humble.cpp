/*
ID: seankeller2010
LANG: C++
TASK: humble
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define INF 2147483647

using namespace std;

int K, N, s;
int S[100];
int best[100];
vector<long> humble;

/*int sea(long i, int begin, int end) {
	if (end - begin == 0) return begin;
	if (i > humble[(begin + end) / 2]) return sea(i, (begin + end) / 2, end);
	return sea(i, begin, (begin + end) / 2);
}*/

int main()
{
	ifstream fin("humble.in");
	ofstream fout("humble.out");
	fin >> K >> N;
	for (int i = 0; i < K; i++) {
		fin >> s;
		S[i] = s;
		humble.push_back(s);
	}
	//for (int i = 0; i < humble.size(); i++) cout << humble[i] << endl;
	//system("PAUSE");
	for (long i = humble.front(); i < humble.back();) {
		long min = INF;
		for (int j = 0; j < K; j++) {
			if (humble[best[j]] * S[j] > i && humble[best[j]] * S[j] < min) min = humble[best[j]] * S[j];
			else {
				while (humble[best[j]] * S[j] <= i) best[j]++;
				//best[j] = sea(i / S[j] + 1, humble[best[j]], humble.size() - 1);
				if (humble[best[j]] * S[j] < min) min = humble[best[j]] * S[j];
			}
		}
		humble.push_back(min);
		sort(humble.begin(), humble.end());
		i = min;
	}
	//for (int i = 0; i < humble.size(); i++) cout << humble[i] << endl;
	//system("PAUSE");
	while (humble.size() < N) {
		long min = INF;
		for (int j = 0; j < K; j++) {
			if (humble[best[j]] * S[j] > humble.back() && humble[best[j]] * S[j] < min) min = humble[best[j]] * S[j];
			else {
				//best[j] = sea(humble.back() / S[j] + 1, humble[best[j]], humble.size() - 1);
				while (humble[best[j]] * S[j] <= humble.back()) best[j]++;
				if (humble[best[j]] * S[j] < min) min = humble[best[j]] * S[j];
			}
		}
		humble.push_back(min);
	}
	//for (int i = 0; i < humble.size(); i++) cout << humble[i] << endl;
	fout << humble[N - 1] << endl;
	//system("PAUSE");
    return 0;
}

