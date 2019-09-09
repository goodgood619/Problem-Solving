#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <math.h>
#include <iostream>
#include <string>
#include <climits>
#include <functional>
using namespace std;
vector<int> v;
void go(int n, int i) {
	if (n < i) {
		v.push_back(n);
		return;
	}
	else {
		go(n / i, i);
		go(n%i, i);
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		bool no = false;
		for (int i = 2; i <= 64; i++){
			v.clear();
			go(n, i);
			no = false;
			for (int j = 0; j < v.size() / 2; j++) {
				int left = v[j];
				int right = v[v.size() - 1 - j];
				if (left == right)continue;
				else {
					no = true;
					break;
				}
			}
			if (!no) break;
		}
		if (!no) printf("1\n");
		else printf("0\n");
	}
	return 0;
}