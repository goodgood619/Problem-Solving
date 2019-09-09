#include <stdio.h>
#include <algorithm>
using namespace std;
bool visited[10001];
void go(int num){
	int self=num;
	int k = num;
	bool check = false;
	while (k < 10000) {
		if (!visited[k] && check) visited[k] = true;
		if (k < 10) {
			int first = k % 10;
			k += first;
			check = true;
		}
		else if (k >= 10 && k < 100) {
			int first = k / 10;
			int second = k % 10;
			k += first;
			k += second;
			check = true;
		}
		else if (k >= 100 && k < 1000) {
			int first = k / 100;
			int second = k / 10 % 10;
			int third = k % 10;
			k += first;
			k += second;
			k += third;
			check = true;
		}
		else if (k >= 1000 && k < 10000) {
			int first = k / 1000;
			int second = k / 100 % 10;
			int third = k / 10 % 10;
			int fourth = k % 10;
			k += first;
			k += second;
			k += third;
			k += fourth;
			check = true;
		}
	}
}
int main() {
	for (int i = 1; i <10000; i++)
		go(i);
	for (int i = 1; i < 10000; i++) if (!visited[i]) printf("%d\n", i);
	return 0;
}