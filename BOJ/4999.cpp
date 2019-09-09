#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
char say[1005];
char doctor[1005];
int main() {
	scanf("%s", say);
	scanf("%s", doctor);
	int length1 = strlen(say);
	int length2 = strlen(doctor);
	if (length1 >= length2) printf("go\n");
	else printf("no\n");
	return 0;
}