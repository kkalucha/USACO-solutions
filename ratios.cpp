/*
ID: seankeller2010
LANG: C++11
TASK: ratios
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>

#define INF 1 << 25
using namespace std;

int sol[3];
int tar[3];
int first[3];
int second[3];
int third[3];
int mult, truemult;

int main()
{
	ifstream fin("ratios.in");
	ofstream fout("ratios.out");
	fin >> sol[0] >> sol[1] >> sol[2] >> first[0] >> first[1] >> first[2] >> second[0] >> second[1] >> second[2] >> third[0] >> third[1] >> third[2];
	int minsum = INF;
	bool found = false;
	for (int i = 0; i <= 100; i++)
		for (int j = 0; j <= 100; j++)
			for (int k = 0; k <= 100; k++)
				if (sol[0] == 0 || (i * first[0] + j * second[0] + k * third[0]) % sol[0] == 0) {
					if (sol[0] == 0 && (i * first[0] + j * second[0] + k * third[0]) != 0) continue;
					if (sol[0] != 0) mult = (i * first[0] + j * second[0] + k * third[0]) / sol[0];
					else if (sol[1] != 0 && (i * first[1] + j * second[1] + k * third[1]) % sol[1] == 0) mult = (i * first[1] + j * second[1] + k * third[1]) / sol[1];
					else if (sol[2] != 0 && (i * first[2] + j * second[2] + k * third[2]) % sol[2] == 0) mult = (i * first[1] + j * second[1] + k * third[1]) / sol[1];
					else mult = 0;
					if (sol[1] == 0 || ((i * first[1] + j * second[1] + k * third[1]) % sol[1] == 0 && (i * first[1] + j * second[1] + k * third[1]) / sol[1] == mult)) {
						if (sol[1] == 0 && (i * first[1] + j * second[1] + k * third[1]) != 0) continue;
						if (sol[2] == 0 || ((i * first[2] + j * second[2] + k * third[2]) % sol[2] == 0 && (i * first[2] + j * second[2] + k * third[2]) / sol[2] == mult)) {
							if (sol[2] == 0 && (i * first[2] + j * second[2] + k * third[2]) != 0) continue;
							if (i + j + k < minsum && (i != 0 || j != 0 || k != 0)) {
								tar[0] = i;
								tar[1] = j;
								tar[2] = k;
								minsum = i + j + k;
								found = true;
								truemult = mult;
							}
						}
					}
				}
	if (found) fout << tar[0] << " " << tar[1] << " " << tar[2] << " " << truemult << endl;
	else fout << "NONE" << endl;
	//system("PAUSE");
    return 0;
}

