#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int n, k, m;
typedef pair<int, int> P;
vector<P>se;
int h = 1;
int arr[6000];
int firstcome[6000];
bool visited[6000];
int position[6000];
#define INF 999999999
stack<int> st;
vector<vector<int>> a;
int cnt,ptr;
void update(int index, int value,int here) {
	index += h - 1;
	se[index] = { value,here };
	while (index > 1) {
		index /= 2;
		se[index] = min(se[2 * index], se[2 * index + 1]);
	}
}
P query(int L, int R, int nodeNum, int nodeL, int nodeR) {
	if (L <= nodeL && nodeR <= R) return se[nodeNum];
	else if (L > nodeR || R < nodeL) return { INF,INF };
	int mid = (nodeL + nodeR) / 2;
	return min(query(L, R, nodeNum * 2, nodeL, mid), query(L, R, nodeNum * 2 + 1, mid + 1, nodeR));
}
void dfs(int here, int depth) {
	if (visited[here]) return;
	visited[here] = true;
	cnt++;
	update(cnt, depth, here);
	position[cnt] = here;
	firstcome[++ptr]=here;
	for (int i = 0; i < a[here].size(); i++){
		int next = a[here][i];
		if (!visited[next]){
			dfs(next, depth + 1);
			cnt++;
			position[cnt] = here;
			update(cnt, depth, here);
		}
	}
	firstcome[++ptr] = here;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++) {
		scanf("%1d", &arr[i]);
	}
	while (h <=2 * n)h <<= 1;
	se.resize(h * 2);
	for (int i = 1; i < se.size(); i++) {
		se[i].first = INF;
		se[i].second = INF;
	}
	int here = 2001;
	int depth =0;
	for (int i = 1; i <= 2 * n; i++) {
		if (arr[i] == 0) {
			arr[i] = here;
			here++;
		}
	}
	a.resize(2*n +2);
	for (int i = 1; i <= 2 * n; i++) {
		if (arr[i] == 1) {
			st.pop();
		}
		else {
			if (st.empty()) {
				st.push(arr[i] - 2000);
			}
			else {
				int here = st.top();
				int next = arr[i] - 2000;
				a[here].push_back(next);
				a[next].push_back(here);
				st.push(next);
			}
		}
	}

	dfs(1, 0);
	int left, right,L=0,R=0;
	scanf("%d%d", &left, &right);
	for (int i = 1; i <= 2 * n; i++) {
		if (position[i] == firstcome[left] && L==0) {
			L = i;
			break;
		}
	}
	for (int i = 1; i <= 2 * n; i++) {
		if (position[i] == firstcome[right] && R == 0) {
			R = i;
			break;
		}
	}
	if (L > R) {
		int temp = L;
		L = R;
		R = temp;
	}
	int dele=query(L, R, 1, 1, h).second;
	for (int i = 1; i <= 2 * n; i++) {
		if (firstcome[i] == dele) printf("%d ",i);
	}
	return 0;
}