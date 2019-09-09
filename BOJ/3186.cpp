#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int K, L, N;
char str[10004];
int usecnt, cnt, flushcnt;
int main() {
	scanf("%d%d%d", &K, &L, &N);
	scanf("%s", str);
	str[N] = '0';
	for (int i = 0; i <strlen(str); i++) {
		if (str[i] == '1' && usecnt != K) {
			usecnt++;
			continue;
		}
		if (str[i] == '0' && usecnt!=K) {
			usecnt = 0;
			continue;
		}
		if (usecnt == K) //사용중이된것
		{
			if (i == strlen(str) - 1) //사용중이됐는데 문자열의끝이면?
			{
				printf("%d\n", i + L);
				cnt++;
				continue;
			}
			if (str[i] == '0' && flushcnt != L) {
				flushcnt++;
			}
			if (str[i] == '1') flushcnt = 0; // 중간에 1나오면 걍 처음부터 다시세자
			if (flushcnt == L) {
				cnt++;
				printf("%d\n", i + 1);
				usecnt = 0;
				flushcnt = 0;
				continue;
			}
		}
	}
	if (cnt == 0)printf("NIKAD\n");
	return 0;
}