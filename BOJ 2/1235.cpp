#include <cstdio>
#include <cstdint>
#include <string>
#include <set>
using namespace std;
typedef int32_t Int;
typedef int64_t ll;
int main() {
	Int n;
	scanf("%d", &n);
	string *s = new string[n];
	for (int i = 0; i < n; i++) {
		char* c = new char[101];
		scanf("%s", c);
		s[i] = c;
	}
	int cnt = 1;
	for (int i = s[0].size() - 1; i >= 0; i--) {
		set<string> check;
		for (int j = 0; j < n; j++) {
			check.insert(s[j].substr(i, cnt));
		}
		if (check.size() == n) {
			printf("%d\n", cnt);
			return 0;
		}
		cnt++;
	}
	return 0;
}