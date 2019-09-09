#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <map>
using namespace std;
int n, m,Max;
int board[505][505];
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
typedef pair <int, int> P;
queue <P> q;
bool visited[505][505];
int a, b, c;
char s[10];
int arr[3];
int ans[3];
int main(){
	scanf("%d%d%d", &arr[0], &arr[1], &arr[2]);
	scanf("%s", s);
	int length = strlen(s);
	sort(arr, arr + 3);
	for (int i = 0; i < length; i++) {
		if (s[i] == 'A') {
			ans[i] = arr[0];
		}
		else if (s[i] == 'B') {
			ans[i] = arr[1];
		}
		else if (s[i] == 'C') {
			ans[i] = arr[2];
		}
	}
	for (int i = 0; i < 3; i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}