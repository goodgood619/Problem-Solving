#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <map>
#include <string>
#include <iostream>
using namespace std;
int n, m,p;
string temp;
map<string, int> hear;
string ans[500005];
string nothear[500005];
string notsee[500005];
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		cin >> nothear[i];
		if (hear.count(nothear[i]) == 0) {
			hear[nothear[i]] = 1;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> notsee[i];
		if (hear.count(notsee[i]) != 0){
			ans[p++] = notsee[i];
		}
	}

	sort(ans, ans + p);
	printf("%d\n", p);
	for (int i = 0; i <p; i++) {
		printf("%s\n", ans[i].c_str());
	}
	return 0;
}