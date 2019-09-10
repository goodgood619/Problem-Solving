#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
char n[15];
int cnt;
long long a, b;
long long ans=9999999999;
bool visited[15];
char temp[15];
bool check;
void go(int index, int depth){
	if (check) return;
	if (cnt == depth) {
		int p = 0;
		b = 0;
		for (int i = depth-1; i >= 0; i--) {
			int number = temp[i] - '0';
			b+=number*pow(10, p);
			p++;
		}
		if (b <= a) {
			ans = min(abs(a - b), ans);
			return;
		}
		else if (b > a) check = true;
		return;
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (!visited[i]) {
				visited[i] = true;
				temp[index] = i + '0';
				go(index + 1, depth + 1);
				visited[i] = false;
				temp[index] = ' ';
			}
		}
	}
}
int main(){
	scanf("%s", n);
	cnt = strlen(n);
	int k = 0;
	for (int i = cnt- 1; i >= 0; i--){
		int number = n[i] - '0';
		a+=number*pow(10, k);
		k++;
	}
	if (cnt > 10) printf("9876543210\n");
	else {
		go(0, 0);
		printf("%lld\n", a - ans);
	}
	return 0;
}