/*
ID: seankeller2010
LANG: C++
TASK: agrinet
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>

#define INF 1 << 25

using namespace std;

int N;
int distancee[100];
int fiber[100][100];
bool intree[100];
int cost;
int treesize = 1;

int main()
{
	ifstream fin("agrinet.in");
	ofstream fout("agrinet.out");
	fin >> N;
	for (int i = 0; i < N; i++) distancee[i] = INF;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			int temp = 0;
			fin >> temp;
			fiber[i][j] = temp;;
		}
	intree[0] = true;
	for (int i = 0; i < N; i++)
		distancee[i] = fiber[0][i];
	while (treesize < N) {
		int mindist = INF;
		int node = 0;
		for (int i = 0; i < N; i++)
			if (intree[i] == false && distancee[i] < mindist) {
				mindist = distancee[i];
				node = i;
			}
		treesize++;
		cost += distancee[node];
		intree[node] = true;
		for (int j = 0; j < N; j++)
			if (fiber[node][j] < distancee[j])
				distancee[j] = fiber[node][j];
	}
	fout << cost << endl;
	//system("PAUSE");
    return 0;
}