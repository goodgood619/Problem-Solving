#include <cstdio>
#include <string.h>
using namespace std;
int main() {
	char* a = new char[21];
	scanf("%s", a);
	int length = strlen(a);
	long long sum = 0,cnt = 1;
	for (int i = length-1; i >=0; i--,cnt*=26) {
		if (i == length-1) {
			sum += (a[i] - 'A' + 1);
			continue;
		}
		sum += cnt* (a[i] - 'A' + 1);
	}
	printf("%lld\n", sum);
	return 0;
}