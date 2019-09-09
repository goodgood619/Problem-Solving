#include <stdio.h>
int arr[1000000];
int n;
void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}
void threesort(int *left,int *mid, int *right) {
	if (*left > *right) swap(left, right);
	if (*left > *mid) swap(left, mid);
	if (*mid > *right) swap(mid, right);
}
int part(int left, int right) {
	int mid = (left + right) / 2;
	threesort(&arr[left], &arr[mid], &arr[right]); // 미리 3개의 값을 정렬을 시키자
	int pidx = mid, pvalue = arr[mid];
	swap(&arr[pidx], &arr[right-1]); // 미리 오른쪽으로 피벗의 위치를 옮겨줌(처음에 이게 이해하기가 힘듬)
	int idx = left;
	for (int i = left; i < right-1; i++) {
		if (arr[i] < pvalue) { // 값이 피벗값보다 작다면, idx와 i위치를 교환시켜줌
			swap(&arr[idx], &arr[i]);
			idx++;
		}
	}
	swap(&arr[idx], &arr[right-1]); // 이것을 왜해주냐면, 위에서 미리 오른쪽으로 피벗의 위치를 옮겨놨기 때문에, 다시 옮겨줘야함
								  // 즉 0부터 idx-1까지는 전부다, pvalue값보다 작기때문에, idx위치에 원래 기존의 값인 피벗이 들어가게 되면, idx+1~right는 전부다 피벗보다 값이 같거나 크므로
								  // 다시 기존의 위치로 옮겨줘야 한다(이해하기 힘듬 2)
	return idx; // 진정한 피벗의 위치
}
void qsort(int left, int right) {
	if (left < right) {
		int pidx = part(left, right);
		qsort(left, pidx - 1);
		qsort(pidx + 1, right);
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	qsort(0, n - 1);
	for (int i = 0; i < n; i++) printf("%d\n", arr[i]);
	return 0;
}