#include <cstdio>
#include <algorithm>
using namespace std;
struct item {
	int a, b, c, d;
};
bool check(item item) {
	if (item.a == item.b && item.b == item.c && item.c == item.d && item.d == item.a) {
		return true;
	}
	else return false;
}
item calculate(item item) {
	int a = abs(item.a - item.b);
	int b = abs(item.b - item.c);
	int c = abs(item.c - item.d);
	int d = abs(item.d - item.a);
	item = { a,b,c,d };
	return item;
}
int main() {
	
	while (true) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if (a == 0 && b == 0 && c == 0 && d == 0) {
			break;
		}
		int cnt = 0;
		item item = { a,b,c,d };
		while (!check(item)) {
			item = calculate(item);
			cnt++;
		}
		printf("%d\n", cnt);
		
	}
	return 0;
}