/*
ID: seankeller2010
LANG: C++11
TASK: sort
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

int N;
vector<int> list;

int main()
{
	ifstream fin ("sort.in");
	ofstream fout ("sort.out");
	bool sorted = false;
	fin >> N;
	int count = 0;
	int begin = 0;
	int end = N - 1;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		fin >> temp;
		list.push_back(temp);
	}
	vector<int> copy = list;
	sort(copy.begin(), copy.end());
	reverse(copy.begin(), copy.end());
	if (copy == list) {
		fout << N / 2 << endl;
		//system("PAUSE");
		return 0;
	}
	while (!sorted) {
		sorted = true;
		count++;
		for (int i = begin; i < end; i++)
			if (list[i] > list[i + 1])
				swap(list[i], list[i + 1]);
		end--;
		for (int i = end - 1; i >= begin; i--)
			if (list[i] > list[i + 1])
				swap(list[i], list[i + 1]);
		begin++;
		for (int i = begin; i < end; i++)
			if (list[i] > list[i + 1]) {
				sorted = false;
				break;
			}
	}
	fout << count << endl;
    return 0;
}