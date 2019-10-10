#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
void go(int cnt,int depth,int **arr,vector<int> &v,bool visited[],int &ans,int &n) {
	if (v.size() >= 4 && v[3] != 0) return;
	if (cnt == depth) {
		if (v[3] != 0) return;
		//각이닝을 계산
		int score = 0,outcnt =0,curhit = 0;
		int position[4] = { 0, };
		for (int i = 0; i < 4; i++) position[i] = -1;
		for (int i = 1; i <= n; i++) {
			outcnt = 0;
			memset(position, -1, sizeof(position));
			while (outcnt != 3) {
				curhit %= 9;
				int player = v[curhit];
				int result = arr[i][player];
				if (result == 0) { //아웃
					outcnt++;
					curhit++;
				}
				else if (result == 1) { //안타
					for (int k = 2; k >= 0; k--) { //3루부터
						if (position[k] == -1) continue;
						else {
							int next = k + 1;
							if (next >= 3) {
								score++;
								position[k] = -1;
							}
							else {
								position[next] = 1;
								position[k] = -1;
							}
						}
					}
					position[0] = 1;
					curhit++;
				}
				else if (result == 2) { //2루타
					for (int k = 2; k >= 0; k--) { //3루부터
						if (position[k] == -1) continue;
						else {
							int next = k + 2;
							if (next >= 3) {
								score++;
								position[k] = -1;
							}
							else {
								position[next] = 1;
								position[k] = -1;
							}
						}
					}
					position[1] = 1;
					curhit++;
				}
				else if (result == 3) { //3루타
					for (int k = 2; k >= 0; k--) { //3루부터
						if (position[k] == -1) continue;
						else {
							int next = k + 3;
							if (next >= 3) {
								score++;
								position[k] = -1;
							}
							else {
								position[next] = 1;
								position[k] = -1;
							}
						}
					}
					position[2] = 1;
					curhit++;
				}
				else { //홈런
					for (int k = 2; k >= 0; k--) { //3루부터
						if (position[k] == -1) continue;
						else {
							int next = k + 4;
							if (next >= 3) {
								score++;
								position[k] = -1;
							}
						}
					}
					score++; //타자
					curhit++;
				}
			}
			
		}

		ans = max(ans, score);
		return;
	}

	for (int i = 0; i < 9; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			go(cnt + 1, depth, arr, v, visited, ans,n);
			v.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int** arr = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		arr[i] = new int[9];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 9; j++) {
			scanf(" %d", &arr[i][j]);
		}
	}
	bool visited[9] = {false,};
	for (int i = 0; i < 9; i++) visited[i] = false;
	int ans = 0;
	vector<int> v;
	go(0, 9, arr, v, visited, ans,n);
	printf("%d\n", ans);
	return 0;
}