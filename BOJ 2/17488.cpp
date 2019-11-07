#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> subject;
	int* no = new int[m];
	for (int i = 0; i < m; i++) no[i] = 0;
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		subject.push_back(num);
	}
	vector<vector<int> > ans;
	ans.assign(n, vector<int>());
	for (int i = 0; i < 2; i++) {
		map<int, int> cnt;
		vector<vector<int> > student;
		student.assign(n, vector<int>());
		for (int j = 0; j < n; j++) {
			while (1) {
				int num;
				scanf("%d", &num);
				if (num == -1) break;
				student[j].push_back(num);
				cnt[num]++;
			}
		}
		map<int, int>::iterator it;
		for (it = cnt.begin(); it != cnt.end(); it++) {
			int idx = it->first;
			idx--;
			if (no[idx] == 1) continue;
			if (subject[idx] >= it->second) {
				subject[idx] -= it->second;
				idx++;
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < student[i].size(); j++) {
						if (idx == student[i][j]) {
							ans[i].push_back(idx);
						}
					}
				}
			}
			else {
				no[idx] = 1;
			}
		}
		student.clear();
	}
	for (int i = 0; i < n; i++) sort(ans[i].begin(), ans[i].end());
	for (int i = 0; i < n; i++) {
		if (ans[i].size() == 0) printf("망했어요\n");
		else {
			for (int j = 0; j < ans[i].size(); j++) {
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
