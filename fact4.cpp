/*
ID: seankeller2010
LANG: C++
TASK: fact4
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int N;

int main()
{
	ifstream fin("fact4.in");
	ofstream fout("fact4.out");
	fin >> N;
	int result = 1;
	for (int i = 1; i <= N; i++) {
		int tomult = i;
		while (tomult % 10 == 0) tomult /= 10;
		int working = tomult * result;
		while (working % 10 == 0) working /= 10;
		if (working < 508800) result = working;
		else result = working % 1000000;
	}
	fout << result  % 10 << endl;
	//system("PAUSE");
    return 0;
}