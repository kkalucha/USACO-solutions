/*
ID: seankeller2010
LANG: C++11
TASK: snowboots
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

vector<pair<int, int> > boots;
int snow[10000];
multiset<int> dist;
int N, B, a, b, c;

int main()
{
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		cin >> a;
		snow[i] = a;
	}
	for (int i = 0; i < B; i++) {
		cin >> b >> c;
		boots.push_back(make_pair(b, c));
	}
	sort(boots.begin(), boots.end());
	dist.insert(N - 1);
	for (int i = 0; i < B; i++) {

	}
    return 0;
}

