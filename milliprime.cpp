// milliprime.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define MAX_N 16000000

using namespace std;

bool comp[MAX_N];

void flip(long n) {
	for (long i = n * n; i < MAX_N; i += n) comp[i] = true;
	return;
}

int main()
{
	for (int i = 2; i < 4000; i++) flip(i);
	int count = 0;
	long i = 2;
	for (; count < 1000000; i++) if (!(comp[i])) count++;
	cout << i - 1 << endl;
	system("PAUSE");
    return 0;
}