#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>
using namespace std;
int n, k, p;
map <string, int> m;
map <int, string> MM;
int x[100004];
bool visited[100004];
string Enter[100004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char name[400] = { '\0', };
		char ok[10] = { '\0', };
		scanf("%s%s", name, ok);
		string N;
		string O;
		N = name;
		O = ok;
		if (O == "enter") {
			m[N] = k;
			MM[k] = N;
			k++;
		}
		else if (O == "leave") {
			int K = m[N];
			visited[K] = true;
		}
	}
	for (int i = 0; i < MM.size(); i++) {
		if (!visited[i]) {
			Enter[p] = MM[i];
			p++;
		}
	}
	sort(Enter, Enter + p);
	for (int i = p - 1; i >= 0; i--) {
		printf("%s\n", Enter[i].c_str());
	}
	return 0;
}