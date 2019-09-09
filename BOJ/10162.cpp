#include <cstdio>
#include <algorithm>
using namespace std;
int t,ans1,ans2,ans3;
// int a=300, b=60, c=10 최소횟수 ㅇㅇ
bool check;
void go(int t, int a, int b, int c){
	if (check) return;
	if (t==0){
		ans1 = a;
		ans2 = b;
		ans3 = c;
		check = true;
		return;
	}
	if (t >= 300) go(t-300, a + 1, b, c);
	if (t <300 && t >= 60) go(t - 60, a, b + 1, c);
	if (t < 60 && t >= 10) go(t - 10, a, b, c + 1);
}
int main(){
	scanf("%d", &t);
	go(t, 0, 0, 0);
	if (check) printf("%d %d %d\n", ans1, ans2, ans3);
	else printf("-1\n");
	return 0;
}