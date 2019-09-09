#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;//{endTime, {startTime, idx}}
int t;
int idx = 1;
int cnt[110];
int Real;
vector<PP> a;
vector<PP> b;
bool visited[110];
int ind = 1;
int q;
int main() {
	while (1) {
		scanf("%d", &t);
		if (t == 0)
			break;
		a.clear();
		Real = 0;

		memset(visited, false, sizeof(visited));
		memset(cnt, 0, sizeof(cnt));

		for (int i = 0, s, e; i <t; i++) {
			scanf("%d%d", &s, &e);
			for (int k = s; k<e; k++)
				a.push_back({ e,{ k, i } });
		}
		sort(a.begin(), a.end()); //끝시간을 기준으로 정렬(가장빨리끝나는것부터)
								  // 끝시간:a.first 시작시간 a.second
		for (int i =0; i <a.size(); i++) {
			if (a[i].first == a[i].second.first)
			{
				visited[a[i].second.second] = true;
				continue;
			}
			if (visited[a[i].second.second])
				continue;
			for (int j = i; j<a.size(); j++) {
				if (!visited[a[j].second.second] && cnt[a[j].second.first]<2) {
					cnt[a[j].second.first]++;
					visited[a[j].second.second] = true;
				}
			}
		}
		for (int i = 1; i <= 24; i++) {
			Real += cnt[i];
		}
		printf("On day %d Emma can attend as many as %d parties.\n", idx, Real);
		idx++;
	}
	return 0;
}