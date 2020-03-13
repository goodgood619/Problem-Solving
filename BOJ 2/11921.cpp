#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
typedef int64_t ll;
int main() {
	char in[50000000] = { 0 };
	fread(in, 1, sizeof(in), stdin);
	int n = 0,i=0;
	ll sum = 0;
	char c;
	for (i = 0; in[i] != '\n'; i++) n = n * 10 + in[i] - '0';
	for (int j = 0; j < n; j++) {
		int temp = 0;
		for (i++; in[i] != '\n'; i++) temp = temp * 10 + in[i] - '0';
		sum += temp;
	}
	printf("%d\n%lld\n", n, sum);
	return 0;
}