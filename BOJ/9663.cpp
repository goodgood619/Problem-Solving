#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
int n,ans;
int arr[16];
int ok(int index) {
	for (int i = 0; i < index; i++) {
		if (arr[i] == arr[index]|| abs(i-index)==abs(arr[i]-arr[index])) return 0;

	}
	return 1;
}
void go(int index, int depth){
	if (index == depth) {
		ans++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		arr[index] = i;
		if (ok(index)) {
			go(index + 1, depth);
		}
		else arr[index] = 0;
	}
}
int main(void){
	scanf("%d", &n);
	go(0, n);
	printf("%d\n", ans);
	return 0;
}