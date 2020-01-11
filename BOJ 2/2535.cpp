#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
struct p {
	int nation, number, score;
};
bool compare(const p &a,const p &b) {
	if (a.score != b.score) return a.score > b.score;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<p> v;
	for (int i = 0; i < n; i++) {
		int nation, number, score;
		scanf("%d%d%d", &nation, &number, &score);
		v.push_back({ nation,number,score });
	}
	sort(v.begin(), v.end(), compare);
	int cnt[101] = { 0, };
	int ans = 0;
	for (auto i : v) {
		if (cnt[i.nation] <= 1 && ans<=2) {
			cnt[i.nation]++;
			ans++;
			printf("%d %d\n", i.nation, i.number);
		}
	}
	return 0;
}