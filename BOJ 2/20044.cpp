#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
	int n;
	scanf("%d", &n);
	vector<int> project;
	for (int i = 0; i < 2 * n; i++) {
		int member;
		scanf("%d", &member);
		project.push_back(member);
	}
	sort(project.begin(), project.end());
	int ans = 1e9;
	for (int i = 0, j = project.size() - 1; i <= j; i++, j--) {
		ans = min(ans, project[i] + project[j]);
	}
	printf("%d\n", ans);
	return 0;
}