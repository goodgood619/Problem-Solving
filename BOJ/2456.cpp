#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> P;
P cnt[4];
P original[4];
int n,Max;
int score[4];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int first, second, third;
		scanf("%d%d%d", &first, &second, &third);
		score[1] += first;
		score[2] += second;
		score[3] += third;
		Max = max(Max, score[1]);
		Max = max(Max, score[2]);
		Max = max(Max, score[3]);
		if (first == 1 && second == 2 && third == 3) {
			cnt[1].second.second++;
			cnt[2].second.first++;
			cnt[3].first++;
		}
		else if (first == 1 && second == 3 && third == 2) {
			cnt[1].second.second++;
			cnt[2].first++;
			cnt[3].second.first++;
		}
		else if (first == 2 && second == 1 && third == 3) {
			cnt[1].second.first++;
			cnt[2].second.second++;
			cnt[3].first++;
		}
		else if (first == 2 && second == 3 && third == 1) {
			cnt[1].second.first++;
			cnt[2].first++;
			cnt[3].second.second++;
		}
		else if (first == 3 && second == 1 && third == 2) {
			cnt[1].first++;
			cnt[2].second.second++;
			cnt[3].second.first++;
		}
		else if (first == 3 && second == 2 && third == 1) {
			cnt[1].first++;
			cnt[2].second.first++;
			cnt[3].second.second++;
		}
	}
	int Who = 0;
	int idx = 0;
	int idy = 0;
	for (int i = 1; i <= 3; i++){
		if (Max == score[i]){
			if(idx==0) idx = i;
			else idy = i;
			Who++;
		}
	}

	if (Who == 1) {
		printf("%d %d\n",idx,Max);
	}
	else if(Who==2){
		bool check = false;
		if (cnt[idx].first > cnt[idy].first){
			printf("%d %d\n", idx, Max);
			check = true;
		}
		else if (cnt[idx].second.first > cnt[idx].second.first) {
			printf("%d %d\n", idx, Max);
			check = true;
		}
		else if (cnt[idx].first < cnt[idy].first) {
			printf("%d %d\n", idy, Max);
			check = true;
		}
		else if (cnt[idx].second.first < cnt[idy].second.first) {
			printf("%d %d\n", idy, Max);
			check = true;
		}
		if(!check)printf("0 %d\n",Max);
	}
	else if (Who == 3) {
		for (int i = 1; i <= 3; i++)original[i] = cnt[i];
		sort(cnt + 1, cnt + 4);
		if (cnt[3].first > cnt[2].first){
			int idx1 = 0;
			for (int i = 1; i <= 3; i++) {
				if (original[i].first == cnt[3].first){
					idx1 = i;
					break;
				}
			}
			printf("%d %d\n", idx1, Max);
		}
		else if (cnt[3].second.first > cnt[2].second.first) {
			int idx1 = 0;
			for (int i = 1; i <= 3; i++) {
				if (original[i].second.first == cnt[3].second.first) {
					idx1 = i;
					break;
				}
			}
			printf("%d %d\n", idx1, Max);
		}
		else printf("0 %d\n", Max);
	}
	return 0;
}