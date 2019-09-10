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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
int arr[1000005];
int arr2[1000005];
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr2[i]);
	}
	int start = 0;
	for (int i = 1; i <= n; i++) {
		if (arr2[1] == arr[i]) {
			start = i;
			break;
		}
	}
	int cnt = 1;
	int ptr = 2;
	for (int i = start+1;i!=start; i++) {
		if (i == n + 1) i = 1;
		if (arr[i] == arr2[ptr]) {
			cnt++;
			ptr++;
		}
		else break;
	}
	if (cnt == n) {
		printf("good puzzle\n");
		return 0;
	}
	cnt = 1;
	ptr = 2;
	for (int i = start - 1; i != start; i--) {
		if (i == 0) i = n;
		if (arr[i] == arr2[ptr]) {
			cnt++;
			ptr++;
		}
		else break;
	}
	if (cnt == n) {
		printf("good puzzle\n");
		return 0;
	}
	printf("bad puzzle\n");
	return 0;
}