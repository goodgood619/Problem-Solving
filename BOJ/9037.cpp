#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
using namespace std;
int t;
int arr[150];
int main(){
	scanf("%d", &t);
	while (t--){
		memset(arr, 0, sizeof(arr));
		int n;
		scanf("%d ", &n);
		if (n == 1){
			scanf("%d", &arr[1]);
			printf("0\n");
		}
		else {
			for (int i = 1; i <= n; i++) {
				scanf("%d", &arr[i]);
				if (arr[i] % 2 == 1) arr[i] += 1;
			}
			int cnt = 0;
			int same = 0;
			while (1) {
				same = 0;
				for (int i = 1; i <n; i++) {
					if (arr[i + 1] == arr[i]) same++;
					else break;
				}
				if (same == n - 1) break;
				vector<int> temp;
				for (int i = 1; i <= n; i++) {
					arr[i] /= 2;
					temp.push_back(arr[i]);
				}
				arr[n + 1] = arr[1];
				for (int i = 1; i <= n; i++) {
					arr[i + 1] += temp[i - 1];
					if (arr[i + 1] % 2 == 1) arr[i + 1] += 1;
					else continue;
				}
				arr[1] = arr[n + 1];
				arr[n + 1] = 0;
				cnt++;
			}
			printf("%d\n", cnt);
		}

	}
	return 0;
}