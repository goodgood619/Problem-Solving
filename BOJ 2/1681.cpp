#include <cstdio>
#include <cstdint>
#include <string>
using namespace std;
typedef int32_t Int;
typedef int64_t ll;
int main() {
	Int n, l;
	scanf("%d%d", &n, &l);
	int rank = 0;
	for (int i = 1;; i++) {
		string temp = to_string(i);
		int no = 0;
		for (int j = 0; j < temp.size(); j++) {
			if (temp[j] - '0' == l) {
				no = 1;
				break;
			}
		}
		if (no) continue;
		rank++;
		if (rank == n) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}