/*
ID: seankeller2010
LANG: C++11
TASK: talent
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
#define mp make_pair

int N, W;
double weight[250];
double talent[250];
double bestrat;
double bestw;
double bestt;
vector<int> notinbest;
pair<double, vector<int> > dp[251][1001];

int main()
{
	ifstream fin("talent.in");
	ofstream fout("talent.out");
	fin >> N >> W;
	for (int i = 1; i <= N; i++) {
		fin >> weight[i];
		fin >> talent[i];
	}
	vector<int> empty;
	//for (int i = 0; i <= W; i++) dp[0][i] = mp(0, empty);
	//for (int i = 1; i <= N; i++) cout << weight[i] << " " << talent[i] << endl;
	for (int i = 0; i <= W; i++) dp[0][i] = mp(0, empty);
	for (int i = 0; i <= N; i++) dp[i][0] = mp(0, empty);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= W; j++) {
			if (dp[i - 1][j].first == 0) {
				if (j == 0) {
					dp[i][(int)(j + weight[i])] = mp(talent[i], dp[i - 1][j].second);
					if (weight[i] >= W) {
						if (talent[i] / weight[i] > bestrat) {
							bestrat = talent[i] / weight[i];
							vector<int> pushing;
							for (int k = 1; k < i; k++) pushing.push_back(k);
							for (int k = i + 1; k <= N; k++) pushing.push_back(k);
							notinbest = pushing;
							bestw = weight[i];
							bestt = talent[i];
						}
					}
				}
			}
			else {
				vector<int> todo = dp[i - 1][j].second;
				todo.push_back(i);
				dp[i][j] = mp(dp[i - 1][j].first, todo);
				//if (dp[i][j].first == 0 || j == 0) {
					//dp[i][(int)(j + weight[i])] = mp(dp[i - 1][j].first + talent[i], dp[i - 1][j].second);
				//}
				if (dp[i - 1][j].first > 0 && j + weight[i] >= W) {
					if ((dp[i - 1][j].first + talent[i]) / (j + weight[i]) > bestrat) {
						bestrat = (dp[i - 1][j].first + talent[i]) / (j + weight[i]);
						notinbest = dp[i - 1][j].second;
						for (int k = i + 1; k <= N; k++) notinbest.push_back(k);
						//cout << bestrat << endl;
						bestw = j + weight[i];
						bestt = dp[i - 1][j].first + talent[i];
					}
				}
				else if ((dp[i - 1][j].first + talent[i]) / (j + weight[i]) > dp[i][(int) (j + weight[i])].first /(weight[i] + j)) {
					dp[i][(int)(j + weight[i])] = mp(dp[i - 1][j].first + talent[i], dp[i - 1][j].second);
					//cout << "wow at " << i << " " << j << endl;
				}
			}
		}
	}
	//for (int i = 1; i <= N; i++) {
	//	for (int j = 0; j <= W; j++) cout << dp[i][j].first << " ";
		//cout << endl;
	//}
	//cout << bestrat << endl;
	//cout << bestt << endl;
	//cout << bestw << endl;
	for (int i = 0; i < notinbest.size(); i++) {
		//cout << notinbest[i] << endl;
		if ((talent[notinbest[i]] + bestt) / (weight[notinbest[i]] + bestw) > bestrat) {
			bestrat = (talent[notinbest[i]] + bestt) / (weight[notinbest[i]] + bestw);
			bestt = talent[notinbest[i]] + bestt;
			bestw = weight[notinbest[i]] + bestw;
		}
	}
	fout << (int)(bestrat  * 1000) << endl;
	//system("PAUSE");
    return 0;
}