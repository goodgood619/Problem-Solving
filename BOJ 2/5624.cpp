#include <cstdio>
#include <cstdint>
using namespace std;
typedef int32_t Int;
typedef int64_t ll;
int main() {
	bool* checknum = new bool[400001];
	for (int i = 0; i <= 400000; i++) checknum[i] = false;
	Int n, cnt = 0;
	scanf("%d", &n);
	Int* num = new Int[n];
	for (int i = 0; i < n; i++) scanf(" %d", &num[i]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (checknum[num[i] - num[j] + 200000]) {
				cnt++;
				break;
			}
		}
		for (int j = 0; j <= i; j++) checknum[num[i] + num[j] + 200000] = true;
	}
	printf("%d\n", cnt);
	delete[] num,checknum;
	return 0;
}