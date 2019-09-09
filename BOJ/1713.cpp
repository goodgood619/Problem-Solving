#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
// 계속 중복된놈만 들어올수 있다 ㅇㅇ
using namespace std;
typedef pair<pair<int, int>, int> P;
vector<P> angle;
int n, m;
int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int num;
		scanf("%d", &num);
		if (angle.size() < n){
			bool ok = false;
			for (int i = 0; i < angle.size(); i++) {
				int what = angle[i].first.first;
				if (what == num) {
					angle[i].first.second++;
					ok = true;
					break;
				}
			}
			if (ok) continue;
			angle.push_back({ { num,1 },i });
			continue;
		}
		else {
			bool ok = false;
			for (int i = 0; i < angle.size(); i++) {
				int what = angle[i].first.first;
				if (what == num) {
					angle[i].first.second++;
					ok = true;
					break;
				}
			}
			if (ok) continue;
			else {
				int Min = 99999999;
				int idx = 99999999;
				int eidx = 0;
				// 횟수가 가장작은걸 erase한다.
				for (int i = 0; i < angle.size(); i++) {
					int ti = angle[i].first.second;
					if (Min > ti) {
						Min = ti;
					}
				}
				for (int i = 0; i < angle.size(); i++) {
					if (Min == angle[i].first.second){
						int idx2 = angle[i].second;
						if (idx > idx2) {
							idx = idx2;
							eidx = i;
						}
					}
				}
				angle.erase(angle.begin() + eidx);
				angle.push_back({{num,1 },i});
			}
		}
	}
	sort(angle.begin(), angle.end());
	for (int i = 0; i < angle.size(); i++) {
		printf("%d ", angle[i].first.first);
	}
	return 0;
}

