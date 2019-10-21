/*
ID: seankeller2010
LANG: C++11
TASK: circlecross
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

/* Logically executes array[x] += v. */
void bit_add(int x, int v) {
	for (int i = x | MAXN; i < (MAXN << 1); i += i & -i) {
		BT[i ^ MAXN] += v;
	}
}

/* Returns the sum of array[i] for 0 <= i < x */
int bit_get(int x) {
	int ret = 0;
	for (int i = x - 1; x != 0; i &= i - 1) {
		ret += BT[i];
		if (!i) break;
	}
	return ret;
}

int N;
int numbers[100001];
bool in[100001];
int first[100001];

int main()
{
	ifstream fin("circlecross.in");
	ofstream fout("circlecross.out");
	fin >> N;
	int count = 0;
	for (int i = 0; i < 2 * N; i++) {
		fin >> numbers[i];
		numbers[i]--;
		if (in[numbers[i]]) {
			in[numbers[i]] = false;
			bit_add(first[numbers[i]], -1);
			count += bit_get(i) - bit_get(first[numbers[i]]);
		}
		else {
			first[numbers[i]] = i;
			in[numbers[i]] = true;
			bit_add(i, 1);
		}
	}
	fout << count << endl;
	//system("PAUSE");
    return 0;
}

