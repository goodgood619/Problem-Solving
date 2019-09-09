#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
int n;
struct grade {
	char name[15];
	int kor;
	int eng;
	int math;
};
bool compare(const grade &a, const grade &b) {
	if (a.kor != b.kor) return a.kor > b.kor;
	else if (a.eng != b.eng) return a.eng < b.eng;
	else if (a.math != b.math) return a.math > b.math;
	else {
		if (strcmp(a.name, b.name)< 0)return true;
		else return false;
	}
}
int main(){
	scanf("%d", &n);
	grade anspo[100001];
	for (int i = 1; i <= n; i++) {
		char c[15] = { '\0', };
		int kor, eng, mat;
		scanf("%s %d %d %d", c, &kor, &eng, &mat);
		string s = c;
		anspo[i].kor = kor;
		anspo[i].eng = eng;
		anspo[i].math = mat;
		strcpy(anspo[i].name, c);
	}
	sort(anspo + 1, anspo + n + 1, compare);
	for (int i = 1; i <= n; i++) {
		printf("%s\n", anspo[i].name);
	}
	return 0;
}