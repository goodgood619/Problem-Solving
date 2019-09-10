#include <cstdio>
#include <algorithm>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
typedef pair <char, pair<int, int>> P;
P alphaptr[30];
P temp[30];
string s[100005];
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		char temp[25] = { '\0', };
		scanf("%s", temp);
		s[i] = temp;
	}
	sort(s, s + n);
	int k = 0;
	for (int i = 0; i < n;) {
		char first = s[i][0];
		int j = i + 1;
		while (first == s[j][0]) {
			j++;
		}
		alphaptr[k].first = first;
		alphaptr[k].second.first = i;
		alphaptr[k].second.second = j - 1;
		k++;
		i = j;
	}
	for (int i = 0; i < k; i++) {
		temp[i].first = alphaptr[i].first;
		temp[i].second.first = alphaptr[i].second.first;
		temp[i].second.second = alphaptr[i].second.second;
	}
	for (int i = 0; i < m; i++) {
		char what;
		scanf(" %c", &what);
		for (int j = 0; j < k; j++) {
			if (what == alphaptr[j].first) {
				if (alphaptr[j].second.first>alphaptr[j].second.second) {
					alphaptr[j].second.first = temp[j].second.first;
					printf("%s\n", s[alphaptr[j].second.first].c_str());
					alphaptr[j].second.first++;
					break;
				}
				else {
					printf("%s\n", s[alphaptr[j].second.first].c_str());
					alphaptr[j].second.first++;
					break;
				}
			}
			else continue;
		}
	}
	return 0;
}