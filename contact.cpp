/*
ID: seankeller2010
LANG: C++
TASK: contact
*/

//#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <math.h>

using namespace std;

int lengths[13][4096];
int A, B, N;
vector<pair<int, string> > solutions;

void fillbuck(string index) {
	int value = 0;
	for (int i = 0; i < index.length(); i++) {
		value += pow(2, i) * (int)(index.at(index.length() - 1 - i) - '0');
	}
	lengths[index.length()][value]++;
}

string backto(int i, int j) {
	string toreturn = "";
	for (int k = 0; k < i; k++) {
		toreturn = (char)(j % 2 + '0') + toreturn;
		j /= 2;
	}
	return toreturn;
}

bool compare_s(pair<int, string> in1, pair<int, string> in2) {
	if (in1.first != in2.first) return in1.first < in2.first;
	if (in1.second.length() != in2.second.length()) return in1.second.length() > in2.second.length();
	int value1 = 0;
	int value2 = 0;
	for (int i = 0; i < in1.second.length(); i++) {
		value1 += pow(2, i) * (int)(in1.second.at(in1.second.length() - 1 - i) - '0');
		value2 += pow(2, i) * (int)(in2.second.at(in2.second.length() - 1 - i) - '0');
	}
	return value1 > value2;
}
int main()
{
	ifstream fin("contact.in");
	ofstream fout("contact.out");
	fin >> A >> B >> N;
	string result = "";
	while (!fin.eof()) {
		string temp = "";
		fin >> temp;
		result += temp;
	}
	for (int i = 0; i < result.length(); i++) {
		for (int j = A; j <= B && j + i <= result.length(); j++) {
			string tocheck = "";
			for (int k = 0; k < j; k++)
				tocheck += result.at(i + k);
			fillbuck(tocheck);
		}
	}
	/*for (int i = A; i <= B; i++)
		for (int j = 0; j < pow(2, i); j++)
			cout << lengths[i][j] << endl;*/
	for (int i = A; i <= B; i++)
		for (int j = 0; j < pow(2, i); j++)
			solutions.push_back(make_pair(lengths[i][j], backto(i, j)));
	//for (int i = 0; i < solutions.size(); i++) cout << solutions[i].second << " : " << solutions[i].first << endl;
	sort(solutions.begin(), solutions.end(), compare_s);
	//for (int i = 0; i < solutions.size(); i++) cout << solutions[i].second << " : " << solutions[i].first << endl;
	int last = 0;
	int count = 0;
	for (int i = 0; !solutions.empty();) {
		pair <int, string> towork = solutions.back();
		solutions.pop_back();
		if (towork.first == 0) break;
		if (towork.first != last) {
			count = 1;
			i++;
			if (i > N) break;
			fout << towork.first << endl;
		}
		else
			count++;
		last = towork.first;
		fout << towork.second;
		if (solutions.back().first != last || count % 6 == 0) fout << endl;
		else fout << " ";
	}
	//system("PAUSE");
    return 0;
}

