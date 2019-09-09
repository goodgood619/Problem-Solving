#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int cow[105][2];
// 소가 왼쪽에 있을때, 왼쪽이경우
// 소가 왼쪽에 있을때, 오른쪽인경우
// 소가 오른쪽에 있을때, 왼쪽인경우
// 소가 오른쪽에 있을때, 오른쪽인경우
int main(){
	int n;
	int cnt = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int first, state;
		scanf("%d%d", &first, &state);
		if (cow[first][state] == 0){
			if (cow[first][1 - state] == 1){
				cow[first][1 - state] = 0;
				cnt++;
			}
			cow[first][state] = 1;
		}
	}
	printf("%d\n", cnt);
	return 0;
}