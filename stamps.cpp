/*
ID: seankeller2010
LANG: C++
TASK: stamps
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <algorithm>

#define INF 1 << 25

using namespace std;

int K, N;
int stamps[50];
bool possible[2000001];
int best[2000001];

int main()
{
	ifstream fin("stamps.in");
	ofstream fout("stamps.out");
	fin >> K >> N;
	for (int i = 0; i < N; i++) fin >> stamps[i];
	sort(stamps, stamps + N);
	fill_n(best, K * stamps[N - 1] + 1, INF);
	possible[0] = true;
	best[0] = 0;
	for (int j = 1; j <= K * stamps[N - 1]; j++) {
		for (int k = 0; k < N; k++)
			if (j - stamps[k] >= 0 && possible[j - stamps[k]]) {
				possible[j] = true;
				if (best[j] > best[j - stamps[k]] + 1) best[j] = best[j - stamps[k]] + 1;
			}
	}
	/*for (int i = 1; i <= K * stamps[N - 1]; i++) cout << possible[i] << " ";
	cout << endl;
	for (int i = 1; i <= K * stamps[N - 1]; i++) cout << best[i] << " ";
	cout << endl;*/
	int longest = 0;
	int current = 0;
	for (int i = 1; i <= K * stamps[N - 1]; i++) {
		if (possible[i] && best[i] <= K) {
			current++;
			if (current > longest) longest = current;
		}
		else current = 0;
	}
	fout << longest << endl;
	//system("PAUSE");
    return 0;
}

