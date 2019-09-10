#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <stack>
using namespace std;
// 흰색이 1,검은색이 2
// 각점에서 가장가깝고 색깔이 같은점을 찾아서 연결한다. 걍 5000이니까 n2으로 해도될듯 ㅇㅇ
// nlogn은 정렬을 한다음에(파랑색따로 빨강색따로) 각각 하나씩해서 한점까지의 lowerbound와 upperbound를 해서
// 둘중에 뭐가 더 작은지 큰지를 정해서 풀면될듯
typedef pair<int, int> P;
P arr[5005];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		arr[i].first = first;
		arr[i].second = second;
	}
	sort(arr + 1, arr + n + 1);
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int here = arr[i].first;
		int color = arr[i].second;
		int Min = 999999999;
		for (int j = 1; j <= n; j++) {
			if (color != arr[j].second || i == j) continue;
			else {
				Min = min(Min, abs(here - arr[j].first));
			}
		}
		sum += Min;
	}
	printf("%d\n", sum);
	return 0;
}