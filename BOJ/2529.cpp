#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
typedef long long ll;
int k, n;
string s;
string small, big;
vector<int> v;
bool visited[12];
vector<int> temp;
ll Max = 0;
ll Min = 100000000000;
void go(int index, int cnt, int depth) {
	if (cnt == depth){
		// 0,2가 부등호
		int ptr = 0;
		bool no = false;
		for (int i = 0; i < s.size(); i += 2) {
			int next = ptr + 1;
			if (s[i] == '<') {
				if (temp[ptr] > temp[next]) {
					no = true;
					break;
				}
				ptr++;
			}
			else {
				if (temp[ptr] < temp[next]) {
					no = true;
					break;
				}
				ptr++;
			}
		}
		if (no) return;
		ll num = 0;
		for (int i = 0; i < temp.size(); i++) {
			num += temp[i] * pow(10, temp.size() - 1 - i);
		}
		if (Max < num){
			Max = num;
			for (int i = 0; i < temp.size(); i++) {
				big[i] = temp[i] + '0';
			}
		}
		if (Min > num) {
			Min = num;
			for (int i = 0; i < temp.size(); i++) {
				small[i] = temp[i] + '0';
			}
		}
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(v[i]);
			go(index + 1, cnt + 1, depth);
			temp.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d ", &k);
	getline(cin,s);
	small.resize(k + 1);
	big.resize(k + 1);
	for (int i = 0; i < 10; i++) v.push_back(i);
	go(0, 0, k + 1);
	cout << big << endl;
	cout << small<< endl;
	return 0;
}