// mountains.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > mountains;
int N, temp1, temp2;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp1 >> temp2;
		mountains.push_back(make_pair(temp1, temp2));
	}
	sort(mountains.begin(), mountains.end());
	int best = mountains[0].first + mountains[0].second;
    return 0;
}

