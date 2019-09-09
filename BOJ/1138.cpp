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
int n;
typedef pair<int, int> P;
P arr[15];
int ans[15];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		arr[i].first = i;
		arr[i].second = num;
	}
	sort(arr + 1, arr + n + 1);
	int total = n;
	for (int i = 1; i <= n; i++){
		int here = arr[i].first;
		int cnt = arr[i].second;
		int temp = 0;
		for (int j = 1; j <= n; j++){
			if (ans[j] != 0) continue;
			else{
				if (cnt == temp){
					ans[j] = here;
					break;
				}
				temp++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}