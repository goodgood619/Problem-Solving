#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
char Num[7];
char Num2[7];
int k,p,idx;
int temp;
int arr[10000];
void go(int num,int cnt) {
	if (num== 0) {
		return;
	}
	else {
		go(num / 12, cnt + 1);
			Num[k++] = num % 12 + '0';
			return;
	}

}
void go2(int num,int cnt) {
	if (num == 0) {
		return;
	}
	else {
		go2(num / 16, cnt + 1);
			Num2[p++] = num % 16 + '0';
		return;
	}
}
int main() {
	for (int i = 1000; i <= 9999;i++){
		k = 0;
		p = 0;
		go(i,0);
		go2(i,0);
		int first = i / 1000;
		int second = i / 100 % 10;
		int third = i / 10 % 10;
		int fourth = i % 10;
		int ten = 0;
		ten += first;
		ten += second;
		ten += third;
		ten += fourth;
		int twelve=0;
		int sixteen=0;
		for (int i = 0; Num[i] != '\0'; i++) {
			int sum = Num[i] - '0';
			twelve+= sum;
		}
		for (int i = 0; Num2[i] != '\0'; i++) {
			int sum2 = Num2[i] - '0';
			sixteen += sum2;
		}
		if (sixteen == twelve && twelve== ten) {
			arr[idx++] = i;
		}
		for (int i = 0; i < 7; i++) {
			Num[i] = '\0';
			Num2[i] = '\0';
		}
	}

	sort(arr, arr + idx);
	for (int i = 0; arr[i] != 0; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}