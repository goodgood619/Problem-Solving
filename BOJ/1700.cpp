#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
vector<int> temp;
int cnt[105];
int arr[105];
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	int Max = 0;
	for (int i = 1; i <= m; i++){
		int num;
		scanf("%d", &num);
		cnt[num]++;
		arr[i] = num;
		Max = max(Max, num);
	}
	int ans = 0;
	for (int i = 1; i <=m; i++){
		int num = arr[i];
		if (temp.size() < n){
			bool no = false;
			for (int j = 0; j< temp.size(); j++) {
				int here = temp[j];
				if (here == num) {
					cnt[num]--;
					no = true;
					continue;
				}
			}
			if (no) continue;
			temp.push_back(num);
			cnt[num]--;
		}
		else if (temp.size() == n){
			bool ok = false;
			int Min = 999999;
			for (int j = 0; j < temp.size();j++){
				int here = temp[j];
				if (here ==num){
					cnt[num]--;
					ok = true;
					break;
				}
			}
			if (ok) continue;
			bool check = false;
			for (int k = 0; k < temp.size(); k++) {
				int plug = temp[k];
				Min = min(Min, cnt[plug]);
			}
			if (Min == 0) {
				for (int k = 0; k < temp.size(); k++) {
					if (cnt[temp[k]] == Min) {
						temp.erase(temp.begin() + k);
						temp.push_back(num);
						check = true;
						cnt[num]--;
						ans++;
						break;
					}
				}
			}
			bool Delete = false;
			if (check) continue;
			int idx = 0;
			int what = 0;
			for (int k = 0; k < temp.size(); k++){
				int here = temp[k];
				for (int j = i + 1; j <= m; j++){
					if (here == arr[j]){
						if (idx<j){
							idx = j;
							what = here;
						}
						break;
					}
					else continue;
				}
			}
			for (int k = 0; k < temp.size(); k++) {
				if (what == temp[k]) {
					temp.erase(temp.begin() + k);
					temp.push_back(num);
					ans++;
					cnt[num]--;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}