#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;
struct p {
	int price;
	string name;
};
bool compare(const p &a, const p &b) {
	if (a.price != b.price) return a.price > b.price;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		int n;
		scanf("%d", &n);
		vector<p> v;
		for (int i = 0; i < n; i++) {
			int price;
			string name;
			cin >> price >> name;
			v.push_back({ price,name });
		}
		sort(v.begin(), v.end(), compare);
		printf("%s\n", v[0].name.c_str());
	}
	return 0;
}