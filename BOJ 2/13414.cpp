#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <string>
using namespace std;
typedef int64_t ll;
int main() {
	int k, l;
	scanf("%d%d", &k, &l);
	map<string, int> m;
	map<int, string> m2;
	for (int i = 0; i < l; i++) {
		char s[9] = { '\0', };
		scanf("%s", s);
		string temp = s;
		m[temp] = i;
	}
	map<string, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		m2[it->second] = it->first;
	}
	map<int, string>::iterator it2;
	for (it2 = m2.begin(); it2 != m2.end(); it2++) {
		printf("%s\n", it2->second.c_str());
		k--;
		if (k == 0) break;
	}
	return 0;
}