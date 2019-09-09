#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n;
typedef pair <int, int> P;
P anspo[100001];
bool visited[100001];
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		memset(anspo, 0, sizeof(anspo));
		memset(visited, false, sizeof(visited));
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &anspo[i].first, &anspo[i].second);
		}
		sort(anspo, anspo + n);
		int sec = anspo[0].second;
		for (int i = 0; i < n - 1; i++) {
			if (anspo[i].second< anspo[i + 1].second) visited[i + 1] = true;
			else {
				if (sec < anspo[i + 1].second) {
					visited[i + 1] = true;
				}
				else if(sec>anspo[i+1].second){
					sec = anspo[i + 1].second;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (!visited[i]) cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}