#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main() {
	int k;
	string s1, s2;
	scanf(" %d", &k);
	cin >> s1 >> s2;
	int correct = 0;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] == s2[i]) correct++;
	}
	if (correct == k) {
		printf("%d\n", s1.size());
	}
	else if (correct > k) {
		printf("%d\n",(s1.size() - (correct - k)));
	}
	else {
		printf("%d\n", s1.size() - k + correct);
	}
	return 0;
}