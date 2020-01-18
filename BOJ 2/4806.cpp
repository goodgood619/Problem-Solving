#include <cstdio>
#include <cstdint>
#include <string>
using namespace std;
typedef int32_t Int;
typedef int64_t ll;
int main() {
	char* s = new char[101];
	int cnt = 0;
	while (scanf(" %[^\n]s", s) != EOF) {
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}