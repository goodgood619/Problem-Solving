#include <stdio.h>
/*k(13>k>6)개의 숫자를 골라 집합 S를 만든 다음 그 숫자만 가지고 번호를 선택
집합 S와 k가 주어졌을 때*/
int k;
int arr[12];
int visit[12];
void go(int cnt, int location) {
	//cnt = 0;
	//location = 0;
	if (location == k && cnt == 6) {
		for (int i = 0; i < k; i++) {
			//visit[i] = 1;
			if (visit[i] == 1)
				printf("%d ", arr[i]);
		}
		printf("\n");
	}
	if (location == k)
		return;
	visit[location] = 1;//방문하면 1이 찍힘
	go(cnt + 1, location + 1);//오른쪽으로 한칸이동, 하나 먹음
	visit[location] = 0;
	go(cnt, location + 1);// 안먹고 오른쪽 이동
}
int main() {
	while (1) {
		scanf("%d", &k);
		if (k == 0)
			return 0;
		else {
			for (int i = 0; i < k; i++) {
				scanf("%d", &arr[i]);
			}
			visit[12] = { 0, };//배열 초기화
			go(0, 0);
		}
		printf("\n");
	}
}