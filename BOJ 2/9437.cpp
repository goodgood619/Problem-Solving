#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <string>
using namespace std;
typedef int64_t ll;
int main() {
	while (true) {
		int n;
		scanf("%d", &n);
		if (n == 0) break;
		int p;
		scanf("%d", &p);
		vector<vector<int>> v;
		for (int i = 1, j = n; i < j; i += 2, j -= 2) {
			vector<int> temp;
			temp.push_back(i), temp.push_back(i + 1),temp.push_back(j),temp.push_back(j-1);
			sort(temp.begin(), temp.end());
			v.push_back(temp);
		}
		for (int i = 0; i < v.size(); i++) {
			int idx = -1;
			for (int j = 0; j < v[i].size(); j++) {
				if (p == v[i][j]) {
					idx = i;
					break;
				}
			}
			if (idx != -1) {
				for (int j = 0; j < v[i].size(); j++) {
					if (p == v[i][j]) continue;
					printf("%d ", v[i][j]);
				}
				printf("\n");
				break;
			}
		}
	}
	return 0;
}