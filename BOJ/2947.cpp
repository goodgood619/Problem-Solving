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
typedef long long ll;
#define INF 1000000000
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0, -1,0,1 };
int goy[4] = { 1, 0,-1,0 };
int arr[5];
int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}
	while (1) {
		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			if (arr[i] == i + 1) cnt++;
		}
		if (cnt == 5) break;
		for (int i = 0, j = 1;j<5; i++, j++) {
			if (arr[i] > arr[j]) {
				swap(arr[i], arr[j]);
				for (int k = 0; k < 5; k++) {
					printf("%d ", arr[k]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}