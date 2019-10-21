/*
ID: seankeller2010
LANG: C++
TASK: ttwo
*/

#include <iostream>
#include <fstream>

using namespace std;

int map[10][10];
int step;
//bool cvisit[400];
//bool fvisit[400];
int cpos[2][2];

void increment(int in) {
	if (cpos[in][1] == 0 && cpos[in][0] / 10 != 0 && map[cpos[in][0] / 10 - 1][cpos[in][0] % 10] != 1) {
		cpos[in][0] -= 10;
		return;
	}
	if (cpos[in][1] == 1 && cpos[in][0] % 10 != 9 && map[cpos[in][0] / 10][cpos[in][0] % 10 + 1] != 1) {
		cpos[in][0]++;
		return;
	}
	if (cpos[in][1] == 2 && cpos[in][0] / 10 != 9 && map[cpos[in][0] / 10 + 1][cpos[in][0] % 10] != 1) {
		cpos[in][0] += 10;
		return;
	}
	if (cpos[in][1] == 3 && cpos[in][0] % 10 != 0 && map[cpos[in][0] / 10][cpos[in][0] % 10 - 1] != 1) {
		cpos[in][0]--;
		return;
	}
	cpos[in][1] = (++cpos[in][1]) % 4;
	return;
}

int main()
{
	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");
	for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) {
		char temp = 0;
		fin >> temp;
		if (temp == 'C') cpos[0][0] = i * 10 + j;
		if (temp == 'F') cpos[1][0] = i * 10 + j;
		if (temp == '*') map[i][j] = 1;
	}
	for (; step < 500000; step++) {
		if (cpos[0][0] == cpos[1][0]) {
			fout << step << endl;
			//system("PAUSE");
			return 0;
		}
		increment(0);
		increment(1);
		//cout << cpos[0][0] << " " << cpos[1][0] << endl;
	}
	fout << "0" << endl;
	//system("PAUSE");
    return 0;
}