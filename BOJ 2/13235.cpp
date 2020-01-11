#include <cstdio>
#include <string.h>
using namespace std;
int main() {
	char* a = new char[21];
	scanf("%s", a);
	int length = strlen(a);
	for (int i = 0, j = length - 1; i < length / 2; i++, j--) {
		if (a[i] != a[j]) {
			printf("false");
			return 0;
		}
	}
	printf("true");
	return 0;
}