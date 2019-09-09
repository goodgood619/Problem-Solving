#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using namespace std;
string s;
vector<int> v, temp, real;
bool visited[25];
bool ok;
char Sum[25][25];
int n;
bool check(int i) {
	for (int j = 0; j < i; j++) {
		int sum = 0;
		for (int k = j; k < i; k++) {
			sum += temp[k];
			if (Sum[j + 1][k + 1] == '+') {
				if (sum > 0) continue;
				else return false;
			}
			else if (Sum[j + 1][k + 1] == '0') {
				if (sum == 0) continue;
				else return false;
			}
			else {
				if (sum < 0) continue;
				else return false;
			}
		}
	}
	return true;
}
void go(int index, int cnt, int depth){
	if (ok) return;
	if (cnt == depth){
		real = temp;
		ok = true;
		return;
	}
	for (int i = 0; i<v.size(); i++) {
			temp.push_back(v[i]);
			if (check(temp.size())) {
				go(index + 1, cnt + 1, depth);
				temp.pop_back();
				
			}
			else {
				temp.pop_back();
			}
		}
}
int main() {
	scanf("%d", &n);
	cin >> s;
	for (int i = -10; i <= 10; i++)v.push_back(i);
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			Sum[i][j] = s[idx++];
		}
	}

	go(0, 0, n);
	for (int i = 0; i < real.size(); i++){
		if (i == real.size() - 1) {
			printf("%d\n", real[i]);
			return 0;
		}
		printf("%d ", real[i]);
	}
	return 0;
}