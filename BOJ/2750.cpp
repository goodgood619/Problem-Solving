#include <stdio.h>
int arr[1000005];
int n;
void swap(int *x,int *y) {
	int left = *x, right = *y;
	int temp = *x;
	*x = *y;
	*y = temp;
}
int partition(int arr[], int left, int right) {
	int pivot = arr[left];
	int i = left, j = right;
	while (i < j) {
		while (pivot < arr[j]) { //j가 pivot보다 같거나 작아지는 위치까지 왼쪽으로 이동함
			j--;
		}
		while (i < j && pivot >= arr[i]) { //i가 pivot보다 커지는 순간까지 이동함
			i++;
		}
		swap(&arr[i], &arr[j]);
	}
	arr[left] = arr[i];
	arr[i] = pivot;
	return i; // pivot위치를 반환함
}
void qsort(int arr[],int left,int right) {
	if (left > right) return;
	if (left < right) {
		int pivotidx = partition(arr, left, right);
		qsort(arr, left, pivotidx - 1);
		qsort(arr, pivotidx + 1, right);
	}
}
int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	qsort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}