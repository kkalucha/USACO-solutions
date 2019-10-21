/*
ID: seankeller2010
LANG: C++
TASK: fracdec
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;

int N, D;
int rems[100000];

int countdig(int n) {
	if (n == 0) return 0;
	return countdig(n / 10) + 1;
}

int main()
{
	ifstream fin("fracdec.in");
	ofstream fout("fracdec.out");
	fin >> N >> D;
	int intpart = N / D;
	int rem = N % D;
	int count = 1;
	string decpart = ".";
	bool terminate = true;
	while (rem != 0) {
		rem *= 10;
		while (rem / D == 0) {
			decpart += "0";
			rems[rem] = count;
			count++;
			rem *= 10;
		}
		if (rems[rem % D]) {
			terminate = false;
			//decpart += (char)((rem / D) + '0');
			break;
		}
		decpart += (char)((rem / D) + '0');
		rem = rem % D;
		rems[rem] = count;
		count++;
	}
	int offset = rems[rem % D];
	//cout << intpart << endl;
	//cout << decpart << endl;
	if (decpart.length() == 1) decpart += "0";
	string result = "";
	if (terminate) result = decpart;
	else {
		decpart += (char)((rem / D) + '0');
		if (decpart.at(decpart.length() - 1) != decpart.at(offset))
			result = decpart.substr(0, offset + 1) + "(" + decpart.substr(offset + 1, decpart.length()) + ")";
		else result = decpart.substr(0, offset) + "(" + decpart.substr(offset, decpart.length() - offset - 1) + ")";
	}
	//int offs = result.find('(');
	//cout << "offs = " << offs << endl;
	//cout << "second to last = " << result.at(result.length() - 2) << " last b4 paren = " << result.at(offs - 1) << endl;
	//cout << "modified: " << result.substr(0, offs - 1) + "(" + result.at(result.length() - 2) + result.substr(offs + 1, result.length() - 3 - offs) + ")";
	if (!terminate) {
		int offs = result.find('(');
		while (result.at(result.length() - 2) == result.at(offs - 1)) {
			result = result.substr(0, offs - 1) + "(" + result.at(result.length() - 2) + result.substr(offs + 1, result.length() - 3 - offs) + ")";
			offs = result.find('(');
		}
	}
	if (intpart) {
		fout << intpart << result.substr(0, 76 - countdig(intpart)) << endl;
		for (int i = 1; result.length() + countdig(intpart) > 76 * i; i++)
			fout << result.substr(76 * i - countdig(intpart), 76) << endl;
	}
	else {
		fout << intpart << result.substr(0, 76 - countdig(intpart) - 1) << endl;
		for (int i = 1; result.length() + countdig(intpart) + 1 > 76 * i; i++)
			fout << result.substr(76 * i - countdig(intpart) - 1, 76) << endl;
	}
	//system("PAUSE");
    return 0;
}