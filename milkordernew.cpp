/*
ID: seankeller2010
LANG: C++11
TASK: milkorder
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
#define max_n 100001

int N, M, temp;
int a[max_n], vis[max_n], d[max_n], v[max_n];
vector<int> g[max_n];
vector<int> rules[50001];
ifstream fin("milkorder.in");
ofstream fout("milkorder.out");

bool works(int x, bool yee) {
	for (int i = 0; i <= N; i++) {
		a[i] = 0;
		vis[i] = 0;
		d[i] = 0;
		v[i] = 0;
		g[i].clear();
	}
	priority_queue<int> q;
	vector<int> unused;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < rules[i].size(); j++) {
			a[j] = rules[i][j];
			vis[a[j]] = 1;
		}
		for (int j = 1; j < rules[i].size(); j++)g[a[j - 1]].push_back(a[j]), d[a[j]]++;
	}
	for (int i = 1; i <= N; i++) {
		if (vis[i]) if (d[i] == 0) q.push(-i), v[i] = 1;
		if (vis[i] == 0) unused.push_back(i);
	}
	vector<int> ans;
	while (!q.empty())
	{
		int u = -q.top(); q.pop(); ans.push_back(u);
		for (int i = 0; i < g[u].size(); i++)
		{
			int j = g[u][i];
			if (!v[j])
			{
				d[j]--; 
				if (d[j] == 0) v[j] = 1, q.push(-j);
			}
		}
	}
	for (int i = 1; i <= N; i++) if (d[i] != 0) return false;
	vector<int> realans;
	int i = 0;
	int j = 0;
	while (i < unused.size() && j < ans.size())
	{
		if (unused[i] <= ans[j])
		{
			realans.push_back(unused[i]);
			i++;
		}
		else
		{
			realans.push_back(ans[j]);
			j++;
		}
	}
	while (i < unused.size())
	{
		realans.push_back(unused[i]);
		i++;
	}

	while (j < ans.size())
	{
		realans.push_back(ans[j]);
		j++;
	}
	//for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
	//for (int i = 0; i < unused.size(); i++) cout << unused[i] << endl;
	if (yee) {
		for (int i = 0; i < realans.size() - 1; i++) fout << realans[i] << " ";
		fout << realans[realans.size() - 1] << endl;
	}
	return true;
}

void binsearch(int x, int y) {
	//cout << "binsearch " << x << " " << y << endl;
	if (y - x < 2) {
		works(x, true);
		//cout << "just ran works " << x << " true" << endl;
		return;
	}
	if (works((x + y) / 2, false)) binsearch((x + y) / 2, y);
	else binsearch(x, (x + y) / 2);
	return;
}

int main()
{
	fin >> N >> M;
	for (int i = 0; i < M; i++) {
		fin >> temp;
		for (int j = 0; j < temp; j++) {
			int tem = 0;
			fin >> tem;
			rules[i].push_back(tem);
		}
	}
	binsearch(1, M + 1);
	//cout << works(2, true) << endl;
	//system("PAUSE");
    return 0;
}

