#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <time.h>
using namespace std;
typedef pair<int, int> P;
int n, m,c;
int onebon[300005];
bool comp(const pair<int, int> &p1,const pair<int, int> &p2) {
	if (p1.first == p2.first) return p1.second < p2.second;
	else return p1.first < p2.first;
}
int main(){
	scanf("%d%d", &n, &c);
	vector<P> anspo;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		onebon[i] = num;
		anspo.push_back({ num,i });
	}
	sort(anspo.begin(),anspo.end());
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		int K =(second - first+1)/2+ 1;
		int randcnt = (second - first + 1);
		bool check = false;
		for (int j = 1; j <=16; j++){
			int findcolor=onebon[first+rand()%randcnt];
			auto idx = lower_bound(anspo.begin(), anspo.end(), P(findcolor,first), comp)-anspo.begin();
			auto idx2 = lower_bound(anspo.begin(),anspo.end(), P(findcolor,second), comp)-anspo.begin();
			auto idx3 = lower_bound(anspo.begin(), anspo.end(), P(findcolor, first), comp);
			auto idx4 = lower_bound(anspo.begin(), anspo.end(), P(findcolor,second), comp);
			int color1 = idx3->first;
			int color2 = idx4->first;
			if (color1 != color2) {
				idx2--;
				idx4--;
			}
			int index1 = idx3->second;
			int index2 = idx4->second;
			if (first <= index1 && index2 <= second) {
				int Size = idx2 - idx + 1;
				if (Size >= K) {
					printf("yes %d\n",findcolor);
					check = true;
					break;
				}
				else continue;
			}
			else {
				int Size = idx2 - idx;
				if (Size >= K) {
					printf("yes %d\n",findcolor);
					check = true;
					break;
				}
				else continue;
			}
		}
		if (!check) printf("no\n");
	}
	return 0;
}