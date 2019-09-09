#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int t,n,idx,cnt,ok;
int main(){
	scanf("%d", &t);
	while (t--) {
		ok = 0;
		cnt = 1;
		typedef pair <int, int> P;
		queue <P> q;
		priority_queue<int, vector<int>> pq;
		scanf("%d%d", &n, &idx);
		for (int i = 0; i < n; i++) {
			int a;
			scanf("%d", &a);
			q.push({ i,a });
			pq.push(a);
		}
		while (!pq.empty()) {
			int index = q.front().first;
			int num = q.front().second;
			int Top = pq.top();
			if (num == Top) {
				if (index == idx) {
					ok = cnt;
					break;
				}
				cnt++;
				pq.pop();
			}
			else q.push({index,num });
			q.pop();
		}
		 printf("%d\n", ok);
	}
	return 0;
}