#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int arr[6];
bool visited[6];
int res = 999999999;
int gcd(int a, int b) {
	if (a%b == 0) return b;
	else return gcd(b%a, a);
}
void go(int index, int cnt, int depth) {
	if (index > 6) return;
	if (cnt == depth){
		vector<int> ans;
		for (int i = 1; i <= 5; i++) {
			if (visited[i]) ans.push_back(arr[i]);
		}
		int a = ans[0];
		int b = ans[1];
		int c = ans[2];
		int Max = gcd(a, b);
		int temp = a / Max*b;
		int Max2 = gcd(temp, c);
		int temp2 = temp / Max2*c;
		res = min(res, temp2);
		return;
	}
	for (int i = index; i <= 5; i++) {
		if (!visited[i]) {
			visited[i] = true;
			go(i + 1, cnt + 1, depth);
			visited[i] = false;
		}
	}
}
int main(){
	for (int i = 1; i <= 5; i++) { scanf("%d", &arr[i]);}
	go(1,0,3);
	printf("%d\n", res);
	return 0;
}