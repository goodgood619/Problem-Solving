#include <stdio.h>
#include <algorithm>
using namespace std;
int n,cnt1,cnt2,cnt3;
char s[101];
char route1[3] = { 'A','B','C' };
char route2[4] = { 'B','A','B','C' };
char route3[6] = { 'C','C','A','A','B','B' };
int main(){
	scanf("%d", &n);
		scanf("%s", s);

	for (int i = 0; i < n; i++) {
		if (s[i] == route1[i % 3]) cnt1++;
		if (s[i] == route2[i % 4]) cnt2++;
		if (s[i] == route3[i % 6]) cnt3++;
	}

	if (cnt1 == cnt2 && cnt2 == cnt3){
		printf("%d\n", cnt1);
		printf("Adrian\n");
		printf("Bruno\n");
		printf("Goran\n");
	}
	else if (cnt1 > cnt2 && cnt1 == cnt3) {
		printf("%d\n", cnt1);
		printf("Adrian\n");
		printf("Goran");
	}
	else if (cnt1 < cnt2 && cnt2 == cnt3) {
		printf("%d\n", cnt2);
		printf("Bruno\n");
		printf("Goran\n");
	}
	else if (cnt1 == cnt2 && cnt1 > cnt3) {
		printf("%d\n", cnt1);
		printf("Adrian\n");
		printf("Bruno\n");
	}
	else if (cnt1 > cnt2 && cnt1 > cnt3){
		printf("%d\n", cnt1);
		printf("Adrian\n");
	}
	else if (cnt2 > cnt1 && cnt2 > cnt3) {
		printf("%d\n", cnt2);
		printf("Bruno\n");
	}
	else if (cnt3 > cnt1 && cnt3 > cnt2) {
		printf("%d\n", cnt3);
		printf("Goran\n");
	}
	return 0;
}