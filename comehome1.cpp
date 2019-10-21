/*
ID: seankeller2010
LANG: C++
TASK: comehome
*/

//#include "stdafx.h"
#include <math.h>
#include <algorithm>
#include <iostream>
#include <fstream>

using namespace std;

int dist[100][100];
int P;

int main()
{
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");
	fin >> P;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (i != j) dist[i][j] = 1 << 25;
	for (int i = 0; i < P; i++) {
		char begin = 0;
		char end = 0;
		int dista = 0;
		fin >> begin >> end >> dista;
		dist[begin - 'A'][end - 'A'] = min(dista, dist[begin - 'A'][end - 'A']);
		dist[end - 'A'][begin - 'A'] = dist[begin - 'A'][end - 'A'];
	}
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			for (int k = 0; k < 100; k++)
				if (dist[j][i] + dist[i][k] < dist[j][k]) dist[j][k] = dist[j][i] + dist[i][k];
	int mini = 1 << 25;
	char cow = 0;
	for (int i = 0; i < 25; i++)
		if (dist[i]['Z' - 'A'] < mini) {
			mini = dist[i]['Z' - 'A'];
			cow = (char)(i + 'A');
	}
	fout << cow << " " << mini << endl;
	//system("PAUSE");
    return 0;
}