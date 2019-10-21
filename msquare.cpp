/*
ID: seankeller2010
LANG: C++11
TASK: msquare
*/

//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std; 

string answer, target;
queue<pair<string, string> > tocheck;
unordered_set<string> visited;

int main()
{
	ifstream fin("msquare.in");
	ofstream fout("msquare.out");
	for (int i = 0; i < 8; i++) {
		char temp = '0';
		fin >> temp;
		target += temp;
	}
	string normal = "12345678";
	if (normal == target) {
		fout << "0" << endl << endl;
		return 0;
	}
	tocheck.push(make_pair(normal, ""));
	while (!tocheck.empty()) {
		string toc = tocheck.front().first;
		string seq = tocheck.front().second;
		int len = seq.length();
		//cout << "toc: " << toc << endl;
		if (len < 1 || seq.at(len - 1) != 'A') {
			toc = string(1, toc.at(7)) + string(1, toc.at(6)) + string(1, toc.at(5)) + string(1, toc.at(4)) + string(1, toc.at(3)) + string(1, toc.at(2)) + string(1, toc.at(1)) + string(1, toc.at(0));
			if (toc == target) {
				answer = seq + "A";
				break;
			}
			//cout << "checked " << seq << "A " << toc << endl;
			if (visited.find(toc) == visited.end())
			{
				visited.insert(toc);
				tocheck.push(make_pair(toc, seq + "A"));
			}
		}
		toc = tocheck.front().first;
		if (len < 3 || seq.at(len - 1) != 'B' || seq.at(len - 2) != 'B' || seq.at(len - 3) != 'B') {
			toc = string(1, toc.at(3)) + string(1, toc.at(0)) + string(1, toc.at(1)) + string(1, toc.at(2)) + string(1, toc.at(5)) + string(1, toc.at(6)) + string(1, toc.at(7)) + string(1, toc.at(4));
			if (toc == target) {
				answer = seq + "B";
				break;
			}
			//cout << "checked " << seq << "B " << toc << endl;
			if (visited.find(toc) == visited.end())
			{
				visited.insert(toc);
				tocheck.push(make_pair(toc, seq + "B"));
			}
		}
		toc = tocheck.front().first;
		if (len < 3 || seq.at(len - 1) != 'C' || seq.at(len - 2) != 'C' || seq.at(len - 3) != 'C') {
			toc = string(1, toc.at(0)) + string(1, toc.at(6)) + string(1, toc.at(1)) + string(1, toc.at(3)) + string(1, toc.at(4)) + string(1, toc.at(2)) + string(1, toc.at(5)) + string(1, toc.at(7));
			if (toc == target) {
				answer = seq + "C";
				break;
			}
			//cout << "checked " << seq << "C " << toc << endl;
			if (visited.find(toc) == visited.end())
			{
				visited.insert(toc);
				tocheck.push(make_pair(toc, seq + "C"));
			}
		}
		tocheck.pop();
	}
	fout << answer.length() << endl << answer << endl;
	//normal.doc();
	//cout << normal.a << " " << normal.b << " " << normal.c << " " << normal.d << " " << normal.e << " " << normal.f << " " << normal.g << " " << normal.h << endl;
	//system("PAUSE");
    return 0;
}

