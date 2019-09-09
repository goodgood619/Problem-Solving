#include <iostream>
#include <map>
#include <string>
using namespace std;
int parent[200001];
int len[200001];
int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}
int merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u != v) {
		parent[u] = v;
		len[v] += len[u];
	}
	return len[v];
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		map < string, int>m;
		scanf("%d", &n);
		for (int i = 1; i <=2*n+1; i++) {
			parent[i] = i;
			len[i] = 1;
		}
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			//string 값을 노드번호로 변환
			int s1index, s2index;
			char s1[25] = { '\0', };
			char s2[25] = { '\0', };
			scanf("%s%s", s1, s2);
			string s3, s4;
			s3 = s1;
			s4 = s2;
			if (m.count(s3) == 0)
				m[s3] = cnt++;
			if (m.count(s4) == 0)
				m[s4] = cnt++;
			printf("%d\n", merge(m[s3], m[s4]));
		}
		m.clear();
	}
}