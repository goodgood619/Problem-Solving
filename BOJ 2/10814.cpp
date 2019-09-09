#include <cstdio>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n;
struct Man{
	int idx, age;
	char name[105];
};
Man man[100000];

void swap(Man &a,Man &b) {
	Man temp = a;
	a = b;
	b = temp;
}
int pivot(int left,int right) {
	int mid = (left + right) / 2;
	int pidx = mid;
	Man pvalue = man[mid];
	swap(man[mid], man[right]);
	int j = left;
	for (int i = left; i < right; i++) {
		if (man[i].age < pvalue.age) { //나이가 작다
			swap(man[j], man[i]);
			j++;
		}
		else if (man[i].age == pvalue.age && man[i].idx <pvalue.idx) { //나이가 같다,만약 더 앞에 있다면 바꿔야 함
			swap(man[j], man[i]);
			j++;
		}
	}
	swap(man[j], man[right]);
	return j;
}
void qsort(int left,int right) {
	if (left < right) {
		int p = pivot(left, right);
		qsort(left, p - 1);
		qsort(p + 1, right);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int age;
		char name[103] = { '\0', };
		scanf("%d%s", &age, name);
		man[i].idx = i, man[i].age = age, strcpy(man[i].name,name);
	}
	qsort(0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d %s\n", man[i].age, man[i].name);
	}
	return 0;
}