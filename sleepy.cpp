/*
ID: seankeller2010
LANG: C++11
TASK: sleepy
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

int N, temp;
int originalline[100001] = { 0 };
vector<int> ordered;

int binsearch(int look, int low, int high){
	if (high <= low) return (look > ordered[low]) ? (low + 1) : low;
	int mid = (low + high) / 2;
	if (look == ordered[mid]) return mid + 1;
	if (look > ordered[mid]) return binsearch(look, mid + 1, high);
	return binsearch(look, low, mid - 1);
}

int main()
{
	ifstream fin("sleepy.in");
	ofstream fout("sleepy.out");
	fin >> N;
	for (int i = 0; i < N; i++) {
		fin >> temp;
		originalline[i] = temp;
	}
	int index = 0;
	for (int i = N - 1; i > 0; i--) if (originalline[i] < originalline[i - 1]) {
		index = i;
		break;
	}
	if (index == 0) {
		fout << 0 << endl;
		return 0;
	}
	fout << index << endl;

	for (int i = index; i < N; i++) ordered.push_back(originalline[i]);
	for (int i = 0; i < index; i++) {
		int loc = binsearch(originalline[i], 0, ordered.size() - 1);
		if (i == index - 1) fout << index - 1 - i + loc;
		else fout << index - 1 - i + loc << " ";
		auto ptr = ordered.begin();
		advance(ptr, loc);
		ordered.insert(ptr, originalline[i]);
	}
	fout << endl;
	//system("PAUSE");
    return 0;
}